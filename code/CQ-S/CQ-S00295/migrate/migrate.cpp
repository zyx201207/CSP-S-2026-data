#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int x[N];
int n;
int d;
int dp[2][N];
int l[N];
int r[N];
int dis[N];
int mark[N];
void work(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		r[i]=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
		l[i]=lower_bound(x+1,x+1+n,x[i]-d)-x; 
		dp[1][i]=dp[0][i]=0;
	}
//	for(int i=1;i<=n;i++) cout<<l[i]<<' ';cout<<"\n";
//	for(int i=1;i<=n;i++) cout<<r[i]<<' ';cout<<"\n";
//	for(int i=n;i>0;i--){
//		dp[0][i]=dp[0][r[i]]+r[i]-i+1-max(0ll,r[i-1]-i+1);
//	}
//	l[n+1]=n+1;
//	dp[1][n+1]=0;
//	for(int i=1;i<=n;i++){
//		dp[1][i]=dp[1][l[i]]+i-l[i]+1-max(0ll,i-l[i+1]+1);
//	}
//	cout<<n<<'\n';
//	for(int i=1;i<=n;i++) cout<<i<<' ';cout<<"\n";
//	for(int i=1;i<=n;i++) cout<<dp[0][i]<<' ';cout<<"\n";
//	for(int i=1;i<=n;i++) cout<<dp[1][i]<<' ';cout<<"\n";
	int ans=0;
	for(int i=1;i<=n;i++){
		if(r[i]-i<2) continue;
//		cout<<i<<" "<<L<<' '<<R<<' '<<ans<<"\n";
//		if(R>=L) ans+=(R-L+1+dp[0][R])*(dp[1][i]+1);
		for(int j=1;j<=n;j++) dis[j]=0x3f3f3f3f3f3f3f3f;
		for(int j=1;j<=n;j++) mark[j]=0;
		queue<int>q;
		q.push(i);
		mark[i]=1;
		dis[i]=0;
		while(!q.empty()){
			int x=q.front();
			q.pop();
			for(int i=x;i<=r[x];i++){
				if(dis[i]>dis[x]+1){
					dis[i]=dis[x]+1;
					mark[i]+=mark[x];
					q.push(i);
				}
				else if(dis[i]==dis[x]+1){
					mark[i]+=mark[x];
				}
			}
		}
		for(int j=i;j<=n;j++) if(mark[j]==2) ans++;
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) work();
	return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
