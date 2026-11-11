#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[1000002],b[1000002];
long long dp[1000002];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	long long ans=0;
	long long l=0,r=0,mid=0;
	for(int i=2;i<=n;i++){
		l=1,r=i;
		while(l<r){
			mid=(l+r)/2;
			if((i-mid+1)*a[i]-(b[i]-b[mid-1])<=m){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
} 
