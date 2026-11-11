#include<bits/stdc++.h>
using namespace std;
int a[100005];
string c[100005];
string v[100005];
bool z[1000005];
int main()
{
	preopen("string.in","r",stdin);
	preopen("string.out","w",stdout);
	int max,n,b;
	string m,x,y;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		v[i]=c[i];
		b+=1;
		for(int j=1;j<=a[i];j++)
		{
			x=x+c[i];
		}
	}
	for(int i=b;i>=1;i--)
	{
		for(int j=a[i];j>=1;j--)
		{
			y=y+c[i];
		}
	}
	max=a[1];
	if(x==y)
	{
		cout<<0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[max]>a[i])
			{
				m=v[max];
			}
			else
			{
				max=i;
			
			}
		}
	}
	cout<<m<<max;
	return 0;
}
