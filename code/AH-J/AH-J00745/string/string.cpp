#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct ac
{
	long long len;
	char op;
}a[200010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].len>>a[i].op;
	}
	int l=1,r=n;
	while(l<r)
	{
		if(a[l].op==a[r].op)
		{
			if(a[l].len==a[r].len)
			{
				l++;
				r--;
			}
			else if(a[l].len<a[r].len)
			{
				a[r].len-=a[l].len;
				l++;
			}
			else
			{
				a[l].len-=a[r].len;
				r--;
			}
		}
		else
		{
			ans+=min(a[l].len,a[r].len);
			if(a[l].len==a[r].len)
			{
				l++;
				r--;
			}
			else if(a[l].len<a[r].len)
			{
				a[r].len-=a[l].len;
				l++;
			}
			else
			{
				a[l].len-=a[r].len;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
