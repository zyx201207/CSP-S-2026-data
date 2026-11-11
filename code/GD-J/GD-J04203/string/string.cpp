#include<bits/stdc++.h>
#define int long long
using namespace std;
char c[200005];
int n,l,r,q,ans,len,a[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n,l=1,r=n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i],len+=a[i];
	while(l<r)
	{
		q=min(a[l],a[r]);
		if(c[l]!=c[r]) ans+=q;
		a[l]-=q,a[r]-=q;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
}
