#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,a[200005],ans,len,l=1,r,cnt;
char b[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		len+=a[i];
	}
	while(l!=r)
	{
		if(a[l]>=a[r])
		{
			if(b[l]!=b[r])
			{
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}
		else
		{
			if(b[l]!=b[r])
			{
				ans+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
