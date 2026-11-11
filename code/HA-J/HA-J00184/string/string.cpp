#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e5+5;
int n,a[N],l=1,r,ans;
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	while(l<r)
	{
		if(a[l]>=a[r])
		{
			if(c[l]!=c[r]) ans+=a[r];
			a[l]-=a[r],r--;
		}
		else
		{
			if(c[l]!=c[r]) ans+=a[l];
			a[r]-=a[l],l++;
		}
	}
	cout<<ans;
	return 0;
}
