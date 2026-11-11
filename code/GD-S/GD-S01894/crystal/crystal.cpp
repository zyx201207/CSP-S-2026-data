#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500010],m,s[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i,an=i;
		while(l<=r){
			int mid=(l+r)/2;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m){
				an=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-an+1);
	}
	cout<<ans;
}
