#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct st
{
	long long cnt;
	long long wei;
	char s;
} a[N];
long long len,ans,m,l,r;
int n;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].cnt>>a[i].s;
		len+=a[i].cnt;
		a[i].wei=len;
	}
	int l=1,r=n;
	while(l<=r)
	{
		if(a[l].s!=a[r].s)
		{
			ans+=min(a[l].cnt,a[r].cnt);
			if(a[l].cnt<a[r].cnt)
			{
				a[r].cnt-=a[l].cnt;
				l++;
			}
			else
			{
				if(a[l].cnt>a[r].cnt)
				{
					a[l].cnt-=a[r].cnt;
					r--;
				}
				else
				{
					l++;
					r--;
				}
			}
		}
		else
		{
			if(a[l].cnt<a[r].cnt)
			{
				a[r].cnt-=a[l].cnt;
				l++;
			}
			else
			{
				if(a[l].cnt>a[r].cnt)
				{
					a[l].cnt-=a[r].cnt;
					r--;
				}
				else
				{
					l++;
					r--;
				}
			}
		}
	}
	cout<<ans;





	return 0;
}

