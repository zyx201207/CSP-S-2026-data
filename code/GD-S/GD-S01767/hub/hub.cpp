#include<bits/stdc++.h>
#define ll long long
#define psb push_back
using namespace std;
const int N=10+5;
int C,T,n,k,ans;
int dis[N];
bool b[N],c[N];
vector<int> ma[N];
void dfs(int x,int step){
	c[x]=false;
	dis[x]=min(dis[x],step);
	for(int y:ma[x]){
		if(c[y]==false) continue;
		dfs(y,step+1);
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		ma[u].psb(v);
		ma[v].psb(u);
	}
	for(int mask=0;mask<(1<<n);mask++){
		memset(b,false,sizeof(b));
		int ccnt=0;
		for(int i=1;i<=n;i++){
			if(mask&(1<<(i-1))) {
				b[i]=true;
				ccnt++;
			}
		}
		int kcnt=ccnt;
		for(int x=1;x<=n;x++){
			for(int y:ma[x]){
				if(b[x]&&b[y]) kcnt--;
			} 
		}
		if(ccnt!=k||kcnt>2) continue;
		memset(dis,127,sizeof(dis));
		int res=0;
		for(int i=1;i<=n;i++){
			if(b[i]){
				memset(c,true,sizeof(c));
				dfs(i,0);
			}
		}
		for(int i=1;i<=n;i++){
			res=max(res,dis[i]);
		}
		ans=min(ans,res);
	}
	cout<<ans<<"\n";
}
void init(){
	for(int i=1;i<=n;i++){
		vector<int> vls;
		ma[i].swap(vls);
	}
	ans=1000000;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--){
		init();
		solve();
	}
	return 0;
}
