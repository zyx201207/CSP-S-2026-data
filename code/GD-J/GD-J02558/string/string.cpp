#include<iostream>
using namespace std;
struct f
{
	long long s;
	char c;
}a[200010];
int n;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(int i = 0;i<n;i++)
	{
		cin>>a[i].s>>a[i].c;
	}
	long long l = 0,r = n-1;
	for(int i = 0;i<n;i++)
	{
		if(l>=r) break;
		if(a[l].c==a[r].c)
		{
			if(a[l].s>a[r].s)
			{
				a[l].s-=a[r].s;
				r--;
			}
			else if(a[l].s<a[r].s)
			{
				a[r].s-=a[l].s;
				l++;
			}
			else
			{
				r--;
				l++;
			}
		}
		else
		{
			if(a[l].s<a[r].s)
			{
				a[r].s-=a[l].s;
				ans+=a[l].s;
				l++;
			}
			else if(a[l].s==a[r].s)
			{
				ans+=a[l].s;
				l++,r--;
			}
			else
			{
				a[l].s-=a[r].s;
				ans+=a[r].s;
				r--;
			}
			
		}
		
	}
	cout<<ans;
	return 0;
 } 
