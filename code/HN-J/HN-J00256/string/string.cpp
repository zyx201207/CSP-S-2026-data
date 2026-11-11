#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],b[200005];
string d,c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int x=1;
	for(int j=1;j<n;j++)
	{
		if(c[j]==c[j+1])
		{
			b[x]=a[j]+a[j+1];
			d[x]=c[j];
		}
		else if(x==1)
		{
			b[x]=a[j];
			d[x]=c[j];x++;
		}
		else
		{
			x++;
			b[x]=a[j];
			d[x]=c[j];
		}
	}
	cout<<0;
	return 0;
 } 
