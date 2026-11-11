#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
int a[200010];
char c[200010];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int ans=0;
	int l=1,r=n;
	while(l<r)
	{
		if(c[l]!=c[r]) ans+=min(a[l],a[r]);
		if(a[l]>a[r])
		{
			a[l]-=a[r];
			r--;
		}
		else
		{
			a[r]-=a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
