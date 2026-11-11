#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==1){
		cout<<1;
		return 0;
	}
	int l=1,r=2,ans=1,sum=a[1];
	while(l<=r&&r<=n){
		while(a[r]*(r-l)-sum>m){
			sum-=a[l];
			l++;
		}
		while(a[r]*(r-l)-sum<=m&&r<=n){
			sum+=a[r];
			r++;
		}
		ans=max(ans,r-l);
	}
	cout<<ans;
	return 0;
}
