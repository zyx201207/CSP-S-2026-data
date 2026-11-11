#include<bits/stdc++.h>
using namespace std;
long long int n,ans=0,lastl=0,lastr=0,l,r;
struct node
{
	long long int d;
	char c;
} a[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long int i=1;i<=n;i++)
	{
		cin>>a[i].d;
		cin>>a[i].c;
	}
	l=1;
	r=n;
	while(l<=r)
	{
		if(l==r)
		{
			break;
		}
		a[l].d-=lastl;
		a[r].d-=lastr;
		lastl=0;
		lastr=0;
		if(a[l].c==a[r].c)
		{
			if(a[l].d>a[r].d)
			{
				lastl=a[r].d;
				r--;
			}
			else if(a[l].d<a[r].d)
			{
				lastr=a[l].d;
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
			ans+=min(a[l].d,a[r].d);
			if(a[l].d>a[r].d)
			{
				lastl=a[r].d;
				r--;
			}
			else if(a[l].d<a[r].d)
			{
				lastr=a[l].d;
				l++;
			}
			else
			{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
