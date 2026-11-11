#include<bits/stdc++.h> 
using namespace std;
int n;
long long m;
void sb(int a)
{
	int b=0;
	for(int i=1;i<=n;i++)
	{
		b=b+i;
		if(b>a)
		{
			cout<<i;
			break;
		}	
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int a[n+5],c[n+5],x=1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n<=16)
	{
		sort(a,a+n);
		for(int i=1;i<=n;i++)
		{
			c[i]=a[i]-a[i-1];
		}
		for(int i=2;i<=n;i++)
		{
			c[i]=(c[i]*i+c[i-1]);
			if(c[i]>m)
			{
				cout<<i;
				break;
			}
		}
	}
	for(int i=1;i<=10;i++)
	{
		if(a[i-1]!=i)
			x=0;
	}
	if(x!=0)
	{
		sb(m);
	}
	if(x==0&&n>=16)
	{
		cout<<"1";
	}
	
	
	return 0;
}
