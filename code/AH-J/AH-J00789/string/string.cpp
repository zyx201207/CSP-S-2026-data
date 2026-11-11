#include<bits/stdc++.h>
using namespace std;
struct hw
{
	long long cd;
	char zf;
};
hw a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,l=1,r,s=0;
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].cd>>a[i].zf;
	}
	for(int i=1;i<=n;i++)
	{
		if(l>=r) break;
		if(a[l].zf!=a[r].zf)
		{
			if(a[l].cd>a[r].cd)
			{
				a[l].cd=a[l].cd-a[r].cd;
				s=s+a[r].cd;
				r--;
				continue;
			}
			if(a[l].cd<a[r].cd)
			{
				a[r].cd=a[r].cd-a[l].cd;
				s=s+a[l].cd;
				l++;
				continue;
			}
			if(a[r].cd==a[l].cd)
			{
				s=s+a[l].cd;
				l++;
				r--;
				continue;
			}
		}
		else
		{
			if(a[l].cd>a[r].cd)
			{
				a[l].cd=a[l].cd-a[r].cd;
				r--;
				continue;
			}
			if(a[l].cd<a[r].cd)
			{
				a[r].cd=a[r].cd-a[l].cd;
				l++;
				continue;
			}
			if(a[r].cd==a[l].cd)
			{
				l++;
				r--;
				continue;
			}
		}
	}
	cout<<s;
	return 0;
}
