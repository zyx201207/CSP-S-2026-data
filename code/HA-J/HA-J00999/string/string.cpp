#include<bits/stdc++.h>
using namespace std;
long long m,ans,x,y;
int n,l,r;
bool f;
struct node
{
	int b;
	char c;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;int i;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].b>>a[i].c;
		m+=a[i].b;
	}
	l=1;r=n;
	if(m%2==1)
	{
		++m;f=1;
	}
	m/=2;
	for(i=1;i<=n;i++)
	{
		if(m-a[i].b<=0)
		{
			x=y=i;break;
		}
		if(m-a[i].b==0)
		{
			a[i].b-=(a[i].b-m)*2;
			if(f==1)
			a[i].b++;
			if(a[i].b==0)
			{
				x=i-1;y=i+1;
			}
			else
			x=y=i;
			break;
		}
		m-=a[i].b;
	}
	while(l<r)
	{
		if(a[l].c==a[r].c)
		{
			if(a[r].b>a[l].b)
			r--;
			if(a[r].b<a[l].b)
			l++;
			if(a[r].b==a[l].b)
			{
				l++;r--;
			}
		}
		else
		{
			if(a[r].b>a[l].b)
			{	
				ans+=a[r].b-a[l].b;
				a[r].b-=a[l].b;
				l++;
			}
			else
			if(a[r].b<a[l].b)
			{	
				ans+=a[l].b-a[r].b;
				a[l].b-=a[r].b;
				r--;
			}
			else
			if(a[l].b==a[r].b)
			{
				ans+=a[l].b;
				l++;r--;
			}
		}
	}
	cout<<ans;
	return 0;
}