#include<bits/stdc++.h>
using namespace std;
const int N=5009;
typedef long long ll;
typedef pair<int,ll> pii;
struct bir{
	int x,w;
};
ll dis[N][N],dp[N][N];
ll a[N];
bool vis[N];
queue<bir>q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n;ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)vis[j]=0,dis[i][j]=1e9;
			q.push({i,0});
			while(!q.empty()){
				int x=q.front().x, w=q.front().w;q.pop();
				if(vis[x])continue;
				vis[x]=1,dis[i][x]=w;
				for(int to=x+1;to<=n&&a[to]-a[x]<=d;to++){
					q.push({to,w+1});
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=0;
			}
		}
		for(int len=1;len<=n;len++){
			for(int l=1;l+len-1<=n;l++){
				int r=l+len-1;
				if(len==1)dp[l][r]=1;
				else if(dis[l][r]==1e9)dp[l][r]=0;
				else{
					dp[l][r]=(a[r]-a[l]<=d);
					for(int k=l+1;k<=r-1;k++){
						if(a[k]-a[l]>d)break;
						if(dis[l][k]+dis[k][r]==dis[l][r])dp[l][r]+=dp[l][k]*dp[k][r];
						if(dp[l][r]>2)break;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(dp[i][j]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

*/