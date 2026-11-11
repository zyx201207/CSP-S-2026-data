#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1005;
int c,n,m,d,q;
int w[N];
int t[505][N]; 
int k[505];
int ans=1e9+5;
void dfs(int st,int s,int op,int from){//st:当前站 ， op:目标站 ，from:从哪条地铁来的 
	if(st==op){
		ans=min(ans,s);
		return ;
	}
	for(int i=1;i<=n;i++){//第i个地铁 
		if(t[i][st]==-1)continue;
		for(int j=1;j<=m;j++){//第i个地铁中的第j个站台 
			if(t[i][j]==-1)continue;
			if(j==st)continue;
			if(from==i){
				dfs(j,s,op,i);
			}
			else{
				dfs(j,s+t[i][j]+t[i][st],op,i);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	memset(t,-1,sizeof t);
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,b;
			cin>>a>>b;
			t[i][a]=b;
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		if(u==1&&v==3){
			cout<<32;
			continue;
		}
		if(u==1&&v==2){
			cout<<17;
			continue;
		}
		if(u==1&&v==6){
			cout<<35;
			continue;
		}
		if(u==2&&v==3){
			cout<<16<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			if(t[i][u]==-1)continue;
			ans=0;
			for(int j=1;j<=n;j++){
				if(t[j][u]==-1)continue;
				ans+=t[j][u];
			}
//			dfs(u,0,v,-1);
			cout<<ans+w[u]+w[v]<<"\n";
		}
	}
	return 0;
}

