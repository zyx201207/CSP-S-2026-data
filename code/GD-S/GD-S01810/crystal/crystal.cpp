#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=0,sum=0;
	ans=1;
	while(l<=r+1&&r<n){
		r++;
		sum+=(a[r]-a[r-1])*(r-l);
		while(sum>m){
			sum-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
