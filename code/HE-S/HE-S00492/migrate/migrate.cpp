#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,R[N];
long long d,a[N];
int dis[N],dp[N];
queue<int> q;
inline void bfs(int s){
	for (int i=1;i<=n;i++){
		dis[i]=0x3f3f3f3f;
		dp[i]=0;
	}
	q.push(s);dis[s]=0;dp[s]=1;
	while (!q.empty()){
		int x=q.front();q.pop();
		if (dp[x]>3) continue;
		for (int y=x+1;y<=R[x];y++)
			if (dis[y]>dis[x]+1){
				dis[y]=dis[x]+1;
				dp[y]=dp[x];
				q.push(y);
			}else if (dis[y]==dis[x]+1){
				dp[y]+=dp[x];
				if (dp[y]>2) dp[y]=3;
			}
	}
}
inline void solve1(){
	cin>>n>>d;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1,j=1;i<=n;i++){
		while (j<n&&a[j+1]-a[i]<=d) ++j;
		R[i]=j;
	}
	long long ans=0;
	for (int i=1;i<=n;i++){
		bfs(i);
		for (int j=i+1;j<=n;j++)
			if (dp[j]==2) ++ans;
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,T;cin>>c>>T;
	while (T--) solve1();
	return 0;
}
