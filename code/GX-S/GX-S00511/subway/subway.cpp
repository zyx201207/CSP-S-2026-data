#include<bits/stdc++.h>
#define int long long
using namespace std;

template<class T>
inline void read(T &x,char c=getchar(),int f=1){
	for(x=0;c<'0'||c>'9';c=getchar())if(c==45)f=-1;
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	x*=f;
}
template<class T>
inline void put(T x){
	if(x<0){
		putchar(45);
		signed long long xx=(signed long long)x*(-1);
		if(xx>=10)put(xx/10);
		putchar((xx%10)^48);
	}
	if(x>=10)put(x/10);
	putchar((x%10)^48);
}

const int N=5e5+10,M=500+10;
int c,n,m,d,q;//分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过,以及出行计划数
int w[N];//地铁站的地铁口走到站厅需要w时间

vector<pair<int,int>>at[N];//地铁站的地铁线,地铁线到站厅需要时间
int val[M][M];//tu

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	read(c),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;i++)read(w[i]);
	
	memset(val,0x3f,sizeof val);
	for(int i=1;i<=n;i++)val[i][i]=0;
	
	for(int i=1;i<=n;i++){
		int k;read(k);
		for(int j=1;j<=k;j++){
			int x,t;read(x),read(t);
			
			for(pair<int,int> e:at[x])
				val[i][e.first]=val[e.first][i]=min(val[i][e.first],t+e.second);
			
			at[x].push_back({i,t});
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				val[i][j]=val[j][i]=min(val[i][j],val[i][k]+val[k][j]);
			}
		}
	}
	
	while(q--){
		int l,r,ans=1e18;read(l),read(r);
		
		for(pair<int,int> i:at[l]){
			for(pair<int,int> j:at[r]){
				int num=i.second+val[i.first][j.first]+j.second;
				ans=min(ans,num);
			}
		}
		
		put(w[l]+ans+w[r]),putchar('\n');
	}
	return 0;
}
