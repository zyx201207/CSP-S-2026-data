#include<bits/stdc++.h>
using namespace std;
long long n,m,x;
long long a[500010],k[10000000],b[10000000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
	    x=i;
		for(int j=i;j<=n;j++)
		{
			
			if(k[a[j]]==1)
			{
				x=j;
			}
			k[a[j]]=1;
		}
		for(int h=x;h<=n;h++)
		{
			b[a[h]]++;
		}
		for(int m=i;m<=n;m++)
		    k[a[m]]=0;
			
	}
	for(int i=1;i<m;i++)
		cout<<b[i]<<' ';
	cout<<b[m];
return 0;
}
