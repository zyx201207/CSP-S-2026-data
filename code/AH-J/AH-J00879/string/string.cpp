#include<bits/stdc++.h>
using namespace std;
int n;
long long ss;
struct abc
{
	long long s;
	char c;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].s>>a[i].c;
	int l=1,r=n;
	while(1!=0)
	{
		if(l+1==r)
		{
			if(a[l].c!=a[r].c) ss+=min(a[l].s,a[r].s);
			break;
		}
		if(a[l].c==a[r].c)
		{
			if(a[l].s<a[r].s)
			{
				a[r].s-=a[l].s;
				l++;
			}
			else if(a[l].s>a[r].s)
			{
				a[l].s-=a[r].s;
				r--;
			}
			else
			{
				l++;
				r--;
			}
		}
		else
		{
			if(a[l].s<a[r].s)
			{
				ss+=a[l].s;
				a[r].s-=a[l].s;
				l++;
			}
			else if(a[l].s>a[r].s)
			{
				ss+=a[r].s;
				a[l].s-=a[r].s;
				r--;
			}
			else
			{
				ss+=a[l].s;
				l++;
				r--;
			}
		}
	}
	cout<<ss;
	return 0;
}
