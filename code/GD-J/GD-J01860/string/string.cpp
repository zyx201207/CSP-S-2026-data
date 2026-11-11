#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rig register int
#define N 200005
int n,a[N],ans;
char c[N];
main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(rig i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(rig l=1,r=n;l<r;)
		if(a[l]<a[r]) ans+=(c[l]!=c[r])*a[l],a[r]-=a[l++];
		else ans+=(c[l]!=c[r])*a[r],a[l]-=a[r--];
	cout<<ans;
}
