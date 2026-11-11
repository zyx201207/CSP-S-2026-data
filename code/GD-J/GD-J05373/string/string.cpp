#include<bits/stdc++.h>
using namespace std;
struct R
{
	int num;
	char s;
}a[200005];
long long n;	
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].s;
	}
	int j=n;
	int i=1;
	while(i<j)
	{
		if(a[i].s==a[j].s)
		{
			if(a[i].num>a[j].num)
			{
				a[i].num-=a[j].num;
				j--;
			}
			else if(a[i].num<a[j].num)
			{
				a[j].num-=a[i].num;
				i++;
			}
			else
			{
				i++;
				j--;
			}
			continue;
		}
		if(a[i].num>a[j].num)
		{
			ans+=a[j].num;
			a[i].num-=a[j].num;
			j--;
		}
		else if(a[i].num<a[j].num)
		{
			ans+=a[i].num;
			a[j].num-=a[i].num;
			i++;
		}
		else
		{
			ans+=a[i].num;
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
