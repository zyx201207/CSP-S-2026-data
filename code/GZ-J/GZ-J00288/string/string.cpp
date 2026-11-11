//GZ-J00288 ∑ΩÍ…”Ó 
#include <bits/stdc++.h>
#define upp(i,a,b,c) for(int i=a;i<=b;i+=c)
#define dow(i,a,b,c) for(int i=a;i>=b;i-=c)
#define ll long long
using namespace std;
ll a[200005];
char c[200005];
ll n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	upp(i,1,n,1) cin>>a[i]>>c[i];
	int l=1,r=n;
	ll ans=0;
	while(r-l>=1){
		if(c[r]!=c[l]){
			if(a[r]>a[l]) ans+=a[l],a[r]-=a[l],l++;
			else if(a[r]==a[l]) ans+=a[l],a[r]=0,a[l]=0,l++,r--;
			else ans+=a[r],a[l]-=a[r],r--;
		}
		else{
			if(a[r]>a[l]) a[r]-=a[l],l++;
			else if(a[r]==a[l]) a[r]=0,a[l]=0,l++,r--;
			else a[l]-=a[r],r--;
		}
	}
	cout<<ans;
	return 0;
}
