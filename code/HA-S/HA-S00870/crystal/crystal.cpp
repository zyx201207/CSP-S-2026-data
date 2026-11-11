#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll s[N];
ll a[N];
int n;
ll m;
ll ans=1;
ll l,r,mid;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		l=1,r=i;
		while(l<=r){
			mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m){
				ans=max(ans,i-mid+1);
				r=mid-1;
			}else l=mid+1;
		}
//		cout<<i<<" "<<mid<<endl; 
	}
	cout<<ans;
	return 0;
}

