#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[500005];
ll a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("csystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int mx=-1;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,ret=-1;
		while(l<=r){
			int mid=l+r>>1;
			if(1ll*(i-mid+1)*a[i]-(s[i]-s[mid-1])<=m){
				ret=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		mx=max(mx,i-ret+1);
	}
	cout<<mx;
	
	
	
	return 0;
}
