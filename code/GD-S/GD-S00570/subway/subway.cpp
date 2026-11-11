#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll c,n,m,d,q,cnt=-1;
int w[N];
ll dp[501][501],vis[501];
int x,y;
void dfs(ll rail,ll time){
	if(rail==y){
		if(cnt==-1)cnt=time;
		cnt=min(time,cnt);
		return;
	}
	if(time>cnt&&cnt!=-1)return;
	for(int i=1;i<=d;i++){
		if(!vis[i]&&dp[rail][i]!=0){
			vis[i]=1;
			dfs(i,time+dp[rail][i]+dp[rail][rail]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int last=0;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			dp[i][a]=t;
			dp[a][i]=t;
		}	
	}
	while(q--){
		cin>>x>>y;
		cnt=-1;
		memset(vis,0,sizeof vis);
		vis[x]=1;
		dfs(x,w[x]);
		cout<<cnt+w[y]<<endl;
	}
	return 0;
}

