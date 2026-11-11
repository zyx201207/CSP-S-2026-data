#include<bits/stdc++.h>
using namespace std;
long long n;
long long sum;
struct ss{
	long long s;
	string c;
} a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s>>a[i].c;
	}
	long long l=1,r=n;
	
	while(l<r)
	{
		if(a[l].s==a[r].s&&a[l].c==a[r].c)
		{
			l++;
			r--;
		}
		else if(a[l].c==a[r].c)
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
		}
		else
		{
			if(a[l].s<a[r].s)
			{
				
				a[r].s-=a[l].s;
				sum+=a[l].s;
				l++;
				
			}
			else if(a[l].s>a[r].s)
			{
				
				a[l].s-=a[r].s;
				sum+=a[r].s;
				r--;
			}
			else
			{
				sum+=a[l].s;
				l++;
				r--;
			}
		}
	
	}
	cout<<sum;
	return 0;
}
