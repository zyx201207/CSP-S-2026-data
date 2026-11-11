#include <iostream>
#include <cmath>
using namespace std;
int m,n,maxn=0;
int a[200200];
int er(int n)
{
	int p=0,k=1;
	while(n>1)
	{
		int t=n%2;
		p+=t*k;
		n=n/2;
		k=k*10;
	}
	return p;
}
int shi(int n)
{
	int k=0,p=0;
	while(n>0)
	{
		int t=n%10;
		p+=pow(2,k)*t;
		k++;
	}
	return p;
}
bool cmp(int c,int b) 
{return c>b;}
int main()
{
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			maxn=max(a[i],maxn);
		}
		cout<<maxn;
		return 0;
	}
	if(m==2)
	{
		maxn=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=er(a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=2;j<=i;j++)
			{
				int t=a[i] and a[j];
				maxn=max(maxn,t);
			}
		}
		cout<<shi(maxn);
		return 0;
	}
	return 0;
}
/*4 2
3 15 12 12*/
