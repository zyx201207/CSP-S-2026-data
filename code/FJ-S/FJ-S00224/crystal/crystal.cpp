#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500001],s[500001],l,r,mid,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		l=1;
		r=i;
		while(l<r){
			mid=l+r>>1;
			if((i-mid+1)*a[i]-s[i]+s[mid-1]<=m){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
