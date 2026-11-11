#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans=0;
struct S{
	int len;
	char s;
}a[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].len>>a[i].s;
	for(int l=1,r=n;l<=r;)
	{
		if(a[l].s==a[r].s)
		{
			if(a[l].len>a[r].len)
			{
				a[l].len-=a[r].len;
				r--;
			}
			else if(a[l].len<a[r].len)
			{
				a[r].len-=a[l].len;
				l++;
			}
			else
			{
				l++;
				r--;
			}
		}
		else
		{
			if(a[l].len>a[r].len)
			{
				a[l].len-=a[r].len;
				ans+=a[r].len;
				r--;
				
			}
			else if(a[l].len<a[r].len)
			{
				a[r].len-=a[l].len;
				ans+=a[l].len;
				l++;
			}
			else
			{
				ans+=a[l].len;
				l++;
				r--;	
			}
		}
	}
	cout<<ans;
	return 0;
 } 
