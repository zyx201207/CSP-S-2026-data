#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	long long a;
	char c;
}a[2000005];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].c;
	}
	int j=n;
	for(int i=1;i<j;)
	{
		if(a[i].c!=a[j].c)
		{
			ans+=min(a[i].a,a[j].a);
			if(a[i].a>a[j].a)
			{
				a[i].a-=a[j].a;
				j--;
			}
			else if(a[i].a<a[j].a)
			{
				a[j].a-=a[i].a;
				i++;
			}
			else if(a[i].a==a[j].a)
			{
				i++;
				j--;
			}
		}
		else
		{
			if(a[i].a>a[j].a)
			{
				a[i].a-=a[j].a;
				j--;
			}
			else if(a[i].a<a[j].a)
			{
				a[j].a-=a[i].a;
				i++;
			}
			else if(a[i].a==a[j].a)
			{
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}