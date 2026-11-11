#include <bits/stdc++.h>
using namespace std;
struct node{
	long long k,cy;
	char c;
};
node a[200005];
long long n,l,r,num;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].k>>a[i].c;
		a[i].cy=a[i].k;
	}
	l=1;
	r=n;
	while(l<r)
	{
		if(a[l].c!=a[r].c)
		{
			num+=min(a[l].cy,a[r].cy);
		}
		if(a[l].cy==a[r].cy)
		{
			l++;
			r--;
		}
		else if(a[l].cy>a[r].cy)
		{
			a[l].cy-=a[r].cy;
			r--;
		}
		else
		{
			a[r].cy-=a[l].cy;
			l++;
		}
	}
	cout<<num;
	return 0;
}
