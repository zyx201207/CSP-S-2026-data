#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000010],l,r,ll,rr,ans;
char c[1000010];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(l<=r){
		int lx=ll,rx=rr;
		ll+=min(a[l]-lx,a[r]-rx);
		rr+=min(a[l]-lx,a[r]-rx);
		if(c[l]!=c[r]){
			ans+=min(a[l]-lx,a[r]-rx);
		}
		if(ll>=a[l]){
			l++;
			ll=0;
		}
		if(rr>=a[r]){
			r--;
			rr=0;
		}
	}
	cout<<ans;
}
