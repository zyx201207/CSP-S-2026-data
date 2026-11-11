#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ss,ee;
vector<int>mp[20000005];
vector<int>jz[20000005];
int dp[500005];
int w[500005];
int c,n,m,dii,q;
void dfs(int d,int u){
	if(dp[d]<=u)return;
	dp[d]=u;
	if(ee==d)return;
	for(int i=0;i<(int)mp[d].size();i++){
		dfs((int)mp[d][i],u+(int)jz[d][i]);
	}
}
void ru(int a,int b,int z){
	mp[a].push_back(b);
	jz[a].push_back(z);
	mp[b].push_back(a);
	jz[b].push_back(z);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dii>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		ru(i,i+m+1,w[i]);
	}
	m++;
	for(int i=1;i<=n;i++){
		int x,topp,toop;
		cin>>x;
		cin>>topp>>toop;
		ru(topp+m+i*m,topp+m,toop);
		for(int j=2;j<=x;j++){
			int a,t;
			cin>>a>>t;
			ru(a+m+i*m,topp+m+i*m,0);
			ru(a+m+i*m,a+m,t);
			topp=a;
		}
	}
	for(int i=1;i<=q;i++){
		memset(dp,0x3f,sizeof(dp));
		cin>>ss>>ee;
		dfs(ss,0);
		cout<<dp[ee]<<'\n';
	}
	return 0;
}
