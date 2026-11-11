#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[5005][5005];
vector<int> v[5005];
int czn[5005][5005];
int a[5005];
int r[5005];
int lr[5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,czs=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			r[i]=0;
			lr[i]=0;
			v[i].clear();
			cin>>a[i];
			for(int j=1;j<=n;j++){
				czn[i][j]=0;
				dp[i][j]=2e18;
			}
		}
		for(int i=n-1;i>=1;i--){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					v[i].push_back(j);
					r[j]++;
				}
			}
			for(int j=i+1;j<=n;j++){
				lr[j]=r[j];
			}
			queue<int> q;
			q.push(i);
			dp[i][i]=0;
			czn[i][i]=1;
			while(!q.empty()){
				int x=q.front();
				q.pop();
				for(int y:v[x]){
					lr[y]--;
					if(dp[i][x]+1<dp[i][y]){
						dp[i][y]=dp[i][x]+1;
						czn[i][y]=czn[i][x];
					}else if(dp[i][x]+1==dp[i][y]){
						czn[i][y]=min(3ll,czn[i][y]+czn[i][x]);
					}
					if(lr[y]==0){
						q.push(y);
					}
				}
			}
			for(int j=i+1;j<=n;j++){
				if(czn[i][j]==2){
					czs++;
				}
			}
		}
		cout<<czs<<"\n";
	}
	return 0;
} 
