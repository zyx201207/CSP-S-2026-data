#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e5+5;
int n,m;
ll a[N],dp[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(dp,-0x3f,sizeof(dp));
	
	dp[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=m;j>0;j--){
			if (j-1>0)
				dp[j]=max(dp[j],dp[j-1]&a[i]);
			else if(j-1==0)
				dp[j]=max(dp[j],a[i]);
		}
	
	cout<<dp[m];
	return 0;
}
