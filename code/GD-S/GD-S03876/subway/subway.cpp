#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
const ll INF=1e18;
int c,n,m,d,q,w[N];
ll dp[505][505],ans;
//n是地铁站数 
//m是地铁线路数
struct node{int to,len;};
vector<node>g[N+505];
bool cmp(node x,node y){ return x.to<y.to; }
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(); m=read(); n=read(); d=read(); q=read();
	for(int i=1;i<=n;++i)w[i]=read();
	for(int i=1,k;i<=m;++i){
		k=read();
		for(int j=1,a,t;j<=k;++j){
			a=read(); t=read();
			g[a].push_back({i,t});
		} 
	}
	for(int i=1;i<=m;++i)
		for(int j=i+1;j<=m;++j)
			dp[i][j]=dp[j][i]=INF;
	for(int i=1;i<=n;++i){
		for(int j=0;j<(int)g[i].size();++j)
			for(int k=j+1;k<(int)g[i].size();++k)
				dp[g[i][k].to][g[i][j].to]=dp[g[i][j].to][g[i][k].to]=min(dp[g[i][j].to][g[i][k].to],(ll)g[i][j].len+(ll)g[i][k].len);
	}
	for(int k=1;k<=m;++k)
		for(int i=1;i<=m;++i){
			for(int j=1;j<=m;++j){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	while(q--){
		int x,y;
		x=read(); y=read();
		ans=INF;
		for(node i:g[x]){
			for(node j:g[y])
				ans=min(ans,dp[i.to][j.to]+i.len+j.len);
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
