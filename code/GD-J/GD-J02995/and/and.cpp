#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,ma;
int a,dp[N];
vector<int> z[30];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	dp[0]=(1<<31)-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		//dp[0]=max(dp[0],a);
		for(int j=m-1;j>=0;j--)
			dp[j+1]=max(dp[j+1],dp[j]&a);
	}
	cout<<dp[m];
	return 0;
}

