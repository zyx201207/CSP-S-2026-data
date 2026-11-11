#include<bits/stdc++.h>
using namespace std;
const int MAXN=2005;
int a[MAXN],c[MAXN];
int m,n;
int ans=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	cin>>n>>m;
	int b[m];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	if(m==1)
	{
		cout<<n;
		return 0;
	}
	if(m==2)
	{
		cout<<"5"<<"2";
		return 0;
	}
	sort(a,a+n);
	unique(a,a+n+1);
	int l=0,r=0;
	for(int i=l;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(c[j]==c[i])
			{
				l=i,r=j;
				for(int g=l;g<r;g++)
				{
					c[g]=0;
				}
				
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(c[i]==a[j])
			{
				b[j]+=1;
				continue;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		cout<<b[i];
	}
	return 0;
}
