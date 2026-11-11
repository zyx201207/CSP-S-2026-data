#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char b[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i]>>b[i];
	int l=0,r=n-1;
	while(l<=r)
	{
		if(b[l]==b[r])
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
			}
			else
			{
				r--;
				l++;
			}
		}
		else
		{
		    cnt+=min(a[l],a[r]);
		    if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
			}
			else
			{
				r--;
				l++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
