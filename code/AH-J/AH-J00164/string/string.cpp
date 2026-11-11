#include <bits/stdc++.h>
using namespace std;
struct node{
	long long t;
	char c;
};
node a[200001];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].t>>a[i].c;
	int i=1,j=n;
	while(i<j)
	{
		if(a[i].c!=a[j].c)
		{
			if(a[i].t>a[j].t)
			{
				a[i].t-=a[j].t;
				ans+=a[j].t;
				j--;
			}
			else if(a[i].t<a[j].t)
			{
				a[j].t-=a[i].t;
				ans+=a[i].t;
				i++;
			}
			else
			{
				ans+=a[i].t;
				i++,j--;
			}
		}
		if(a[i].c==a[j].c)
		{
			if(a[i].t>a[j].t)
			{
				a[i].t-=a[j].t;
				j--;
			}
			else if(a[i].t<a[j].t)
			{
				a[j].t-=a[i].t;
				i++;
			}
			else i++,j--;
		}
	}
	cout<<ans;
	return 0;
}
