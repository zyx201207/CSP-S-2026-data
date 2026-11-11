#include<bits/stdc++.h>
#include<vector>
#include<queue>
#define endl '\n'
#define ll long long
using namespace std;

inline int min(const int &x, const int &y){return x>y?y:x;}
inline int read(){
	int x=0, f=1, ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0) putchar('-'), x*=-1;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}


const int N=507, M=5e5+7;
struct sid{
	int to;
	ll w;
};
vector<sid> g[N],v[M];
int w[M];
ll dis[N][N];
//dis[i][j] means from-Line-i-to-Line-j min cost

int dfs(int stt, int s){
	
	for(const auto &tost:g[s]){ // A line s to a station i
		
		int i=tost.to;
		for(const auto &toli:v[i]){// A station i to a line j
			
			int j=toli.to;
			ll len=tost.w+toli.w;
			
			if(dis[stt][j]>dis[stt][s]+len){
//				cerr<<s<<" (cst "<<tost.w<<" by "<<i<<" on "<<w[i]<<") to "<<j<<" cst "<<toli.w<<endl;
				dis[stt][j]=dis[stt][s]+len;
				dfs(stt,j);
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c=read(),n=read(),m=read(),d=read(),asks=read();
	
	for(int i=1; i<=m; i++){
		w[i]=read();
	}
	for(int i=1; i<=n; i++){
		int k=read();
		for(int j=1; j<=k; j++){
			int a=read(),t=read();
			g[i].push_back({a,t});//line to station
			v[a].push_back({i,t});//station to line
		}
	}
	memset(dis,0x3f,sizeof(dis));
	
	for(int i=1; i<=n; i++){
		dis[i][i]=0;
		dfs(i,i);
	}
	while(asks--){
		int l=read(),r=read();
		ll ans=LONG_LONG_MAX;
		for(const auto &i:v[l]){// find all LinePair to serch a best way
			for(const auto &j:v[r]){
				ans=min(ans,w[l]+i.w+j.w+w[r]+dis[i.to][j.to]);
			}
		}
		cout<<ans<<endl;
	}
	
//	cerr<<endl<<"0| ";
//	for(int i=1; i<=n; i++) cerr<<i<<" ";
//	cerr<<"\n-+----------\n";
//	for(int i=1; i<=n; i++){
//		cerr<<i<<"| ";
//		for(int j=1; j<=n; j++){
//			cerr<<dis[i][j]<<" ";
//		}
//		cerr<<"|"<<endl;
//	}
	return 0;
}
