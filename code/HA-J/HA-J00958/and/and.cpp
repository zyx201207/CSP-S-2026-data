#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[200005],dp[200005],vis[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int x=0,y=0;
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==0)sum=a[i];
		else sum&=a[i];
	}
	if(n==m){
		cout<<sum;
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(dp[2]<long(a[i]&a[j])){
				dp[2]=a[i]&a[j];
				x=i,y=j;
			}
		}
	}
	vis[x]=1,vis[y]=1;
	for(int j=3;j<=m;j++){
		for(int i=0;i<n;i++){
			if(!vis[i]){
				if(long(dp[j-1]&a[i])>dp[j]){
					dp[j]=dp[j-1]&a[i];
					x=i;
				}
			}
		}
		vis[x]=1;
	}
	cout<<dp[m];
	return 0;
}
