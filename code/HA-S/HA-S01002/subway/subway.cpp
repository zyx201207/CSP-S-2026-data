#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];
int heada[500005]={};
int nxta[500005]={};
int ia[500005];
int ta[500005];
int topa=0;
int g[505][505]={};
int dp[505][505]={};
void adda(int a,int i,int t){
	++topa;
	nxta[topa]=heada[a];
	heada[a]=topa;
	ia[topa]=i;
	ta[topa]=t;
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			g[i][j]=9223372036854775807;
		}
		g[i][i]=0;
	}
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int a,t;
			cin>>a>>t;
			int now=heada[a];
			while(now){
				g[i][ia[now]]=ta[now]+t;
				g[ia[now]][i]=ta[now]+t;
				now=nxta[now];
			}
			adda(a,i,t);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			dp[i][j]=g[i][j];
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(dp[i][k]!=9223372036854775807&&dp[k][j]!=9223372036854775807){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=9223372036854775807;
		int nowx=heada[x];
		while(nowx){
			int nowy=heada[y];
			while(nowy){
				if(dp[ia[nowx]][ia[nowy]]!=9223372036854775807){
					ans=min(ans,w[x]+ta[nowx]+dp[ia[nowx]][ia[nowy]]+ta[nowy]+w[y]);
				}
				nowy=nxta[nowy];
			}
			nowx=nxta[nowx];
		}
		cout<<ans<<'\n';
	}
	return 0;
}

