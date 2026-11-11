#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define ull unsigned long long
#define endl '\n'
#define INF 0x3f3f3f3f
#define pll pair<int,int>
const int N=2e6+5,M=5e3+5;
ll n,d,a[N];
ll dp[M][M],num[M][M];
void init(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)dp[i][j]=INF,num[i][j]=0;
}
void solve(){
	cin>>n>>d;
	init();
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)dp[i][i]=1,num[i][i]=1;
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			ll j=i+len-1;
			if(a[j]-a[i]<=d)dp[i][j]=2;
			for(int k=i+1;k<j;k++)
				if(dp[i][j]>dp[i][k]+dp[k][j]-1)dp[i][j]=dp[i][k]+dp[k][j]-1;
		}
	}
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			ll j=i+len-1;
			for(int k=i+1;k<j;k++){
				if(dp[i][j]==dp[i][k]+dp[k][j]-1){
					num[i][j]+=num[i][k]*num[k][j];
//					cout<<i<<" "<<j<<endl;	
				}
			}
			if(a[j]-a[i]<=d)num[i][j]++;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)cout<<num[i][j]<<" ";
//		cout<<endl;
//	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)if(num[i][j]==2)ans++;
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int sz,T;cin>>sz>>T;
	while(T--)solve();
	return 0;
}

/*
0 1
4 2
1 2 3 4

*/
