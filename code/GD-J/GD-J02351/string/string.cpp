#include <bits/stdc++.h>
using namespace std;
struct node
{
	long long b;
	char c;
};
long long n,l=1,r,ans;
node a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].b>>a[i].c;
	}
	while(l<r)
	{
		if(a[l].b>a[r].b)
		{
			if(a[l].c!=a[r].c)
			{
				ans+=a[r].b;
			}
			a[l].b-=a[r].b;
			a[r].b=0;
			r--;
		}
		else if(a[l].b==a[r].b)
		{
			if(a[l].c!=a[r].c)
			{
				ans+=a[r].b;
			}
			a[r].b=0;
			a[l].b=0;
			r--;
			l++;
		}
		else
		{
			if(a[l].c!=a[r].c)
			{
				ans+=a[l].b;
			}
			a[r].b-=a[l].b;
			a[l].b=0;
			l++;
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
