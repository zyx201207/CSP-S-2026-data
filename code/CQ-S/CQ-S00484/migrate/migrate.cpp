#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,rd[2000005],rdd[2000005];
ll dp[2000005],dis[2000005];
ll d,a[2000005];
vector<int> vec[2000005];
bool vis[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c;
	if(c<=6){
		cin>>t;
		while(t--){
			cin>>n>>d;for(int i=1;i<=n;i++) cin>>a[i],rd[i]=0,vec[i].clear();
			for(int i=1;i<=n;i++) {
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d) vec[i].push_back(j),rd[j]++;
					else break;
				}	
			}
			ll ans=0;
			for(int i=1;i<=n;i++) {
				for(int j=1;j<=n;j++) rdd[j]=rd[j],dis[j]=1e18;
				queue<int> que;que.push(i);dis[i]=0;
				while(!que.empty()){
					int t=que.front();que.pop();
					for(int i:vec[t]){
						rdd[i]--;
						if(dis[t]+1<dis[i]) dis[i]=dis[t]+1;
						if(rdd[i]==0) que.push(i);
					}  
				}for(int j=1;j<=n;j++) rdd[j]=rd[j],dp[j]=0,vis[j]=0;que.push(i);dp[i]=1;
				while(!que.empty()){
					int t=que.front();que.pop();
					if(dp[t]>2) vis[t]=1;
					if(dp[t]==2&&!vis[t]) ans++;
					for(int i:vec[t]){
						rdd[i]--;
						if(dis[t]+1==dis[i]) {
							vis[i]|=vis[t];
							if(!vis[i]) dp[i]+=dp[t];
						}
						if(rdd[i]==0) que.push(i);
					}  
				}
				for(int j:vec[i]) rd[j]--;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 3
10 14
-31 -24 -17 -10 -3 4 11 18 25 32
10 21
0 7 14 21 28 35 42 49 56 63
10 22
0 7 14 21 28 35 42 49 56 63

B:

0 2
8 6
1 4 7 8 9 10 11 12
7 5
2 5 8 9 10 11 12 
*/
