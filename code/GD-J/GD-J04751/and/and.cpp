#include <bits/stdc++.h>
using namespace std;


struct tt
{
	int k[10005];
	int l=0;
}m[105];
string two(int a)
{
	string n;
	while(true)
	{
		n+=a%2+48;
		if(a==1)
		{
			break;
		}
		a/=2;
	} 
	return n;
} 

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,o;
	cin>>n>>o;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		string j=two(t);
		for(int x=0;x<j.size();x++)
		{
			if(j[x]-48)
			{
				m[x].k[m[x].l]=t;
				m[x].l++;
			}
		}
	}
	long long a[o+1];
	for(int i=0;i<100;i++)
	{
		sort(m[i].k,m[i].k+m[i].l);
		if(m[i].l>=o)
		{
			for(int x=m[i].l-1;(m[i].l-1-x)<o;x--)
			{
				a[m[i].l-x]=m[i].k[x];
			}
			break;
		}
	}
	int c=a[1];
	for(int i=2;i<=o;i++)
	{
		c=c & a[i];
	}
	cout<<c;
	return 0;
}
