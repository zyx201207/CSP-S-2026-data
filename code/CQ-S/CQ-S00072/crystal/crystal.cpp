#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int t,l,r,mid,ans,n,m,a[500005],sum[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		l=0;
		r=i-1;
		t=0;
		for(int j=i;j<=n;j++){
			if(a[i]==a[j]){
				t++;
			}
			else{
				break;
			}
		}
		while(l<=r){
			mid=(l+r)/2;
			if(mid*a[i]-sum[i-1]+sum[i-mid-1]<=m){
				ans=max(ans,mid+t);
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
预期100,希望不会挂 
*/
