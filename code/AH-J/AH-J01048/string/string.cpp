#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200005];
char s[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>s[i];
	int l=1,r=n,ans=0;
	while(l<r)
	{
		if(s[l]!=s[r]) ans+=min(a[l],a[r]);
		if(a[l]==a[r]) l++,r--;
		else if(a[l]<a[r]) a[r]-=a[l],l++;
		else a[l]-=a[r],r--;
	}
	cout<<ans;
	return 0;
}
