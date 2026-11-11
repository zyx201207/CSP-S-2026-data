#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=-1;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1;
		while(l<r){
			int mid=(l+r)/2;
			if((i-mid)*a[i]-(s[i-1]-s[mid-1])<=m){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;	
}
