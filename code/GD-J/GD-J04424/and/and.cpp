#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005];
int dp[1005][1005];
ll sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[1][i]=a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			sum=max(sum,a[i]);
		}
		cout<<sum;
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				sum=max(sum,a[i]&a[j]);
			}
		}
		cout<<sum;
		return 0;
	}
	if(m==n){
		sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
		return 0;
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;
}

