#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=2e5+10;
ll n,m;
ll a[N];
ll dp[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(k!=i) dp[i]=max(dp[i-1],a[j]&a[k]);
			}
		}
	}
	
	if(dp[m]==0) cout<<1;
	else cout<<dp[m];
	return 0;
} 
