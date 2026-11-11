#include <bits/stdc++.h>
using namespace std;
long long n,m,a[676767],b[676767],p,x=0,num=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		p+=a[i];
	}
	p/=n;
	for(int i=0;i<n;i++)
	{
		if(a[i]-p>=0)
		{
			b[i]=a[i]-p;
		}
		else
		{
			b[i]=p-a[i];
		}
	}
	sort(b,b+n);
	while(m>0&&x<n)
	{
		m-=b[x];
		x++;
		num++;
		if(m<0)
		{
			break;
		}
		else if(m==0)
		{
			
			break;
		}
		
	}
	cout<<num;
	return 0;
}
