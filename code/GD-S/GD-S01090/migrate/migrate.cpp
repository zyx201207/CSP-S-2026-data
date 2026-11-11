#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define pb push_back
#define V vector
const int N=2e6+10;
int x[N];
int sum[N],dp[N][2];//0：最短路径 1：数量 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int cid,T;cin>>cid>>T;
	while(T--){
		int n,d;cin>>n>>d;
		FOR(i,1,n)cin>>x[i];
		int ans=0;
		FOR(st,1,n-1){
			FOR(i,1,n)sum[i]=dp[i][0]=dp[i][1]=0;
			deque<int>q;q.pb(st);
			sum[0]=1;
			FOR(ed,st+1,n){
				while(!q.empty()&&x[ed]-x[q.front()]>d){
					sum[dp[q.front()][0]]--;
					q.pop_front();
				}
				if(q.empty()) break;
				dp[ed][0]=dp[q.front()][0]+1;
				dp[ed][1]=sum[dp[q.front()][0]];
				if(dp[ed][1]==2) ans++;
				while(!q.empty()&&dp[q.back()][0]>dp[ed][0]){
					sum[dp[q.back()][0]]--;
					q.pop_back();
				}
				q.pb(ed);
				sum[dp[ed][0]]++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
Nemiga?
Furia?
how to do?
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
