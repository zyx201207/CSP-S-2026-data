#include<bits/stdc++.h>
using namespace std;
long long n,s=0,c[10000001],a[10000001],b[10000001],e[10000001],k=1,g=1,m,w;
char f;
void er(int x)
{
	g=1;
	for(int i=1;i<=x;i++) c[i]=0;
	for(int i=x;i!=0;i/=2)
	{
		c[g]=i%2;
		g++;
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=m;i++)
	{
		b[i]=a[n-i+1];
	}
	er(b[1]);
	w=a[n];
	for(int i=1;i<=w;i++)
	{
		e[i]=c[i];
	}
	for(int i=2;i<=m;i++)
	{
		er(b[i]);
		for(int i=1;i<=w;i++)
		{
			if(c[i]!=e[i]) e[i]=0;
		}
	}
	for(int i=1;i<=w;i++)
	{
		s+=e[i]*k;
		k*=2;
	}
	cout<<s;
	return 0; 
}
