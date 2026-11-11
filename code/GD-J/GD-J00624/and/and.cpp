#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],dp[200005],dd[200005];
bool p[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		dp[i]=a[i]&a[i+1];
		for(int k=1;k<=m;k++){
			for(int j=i+2;j<=n;j++){
				if(dp[i]<dp[i]&a[j]&&!p[j]){
					p[j]=1;
					dp[i]=dp[i]&a[j];
				}
			}
		}
		
	}
	ll maxx=-1;
	for(int i=1;i<=n;i++){
		maxx=max(maxx,dp[i]);
	}
	cout<<maxx<<"\n";
	
	return 0;
} 
