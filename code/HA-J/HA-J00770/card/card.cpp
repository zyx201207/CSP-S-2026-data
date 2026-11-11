#include <bits/stdc++.h>
using namespace std;
int n,m,f,r,front1,rest1;
int Qa[500005],Sa[500005],c[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>Qa[r++];
	for(int i=0;i<n;i++)
	{
		f=i;
		r=n-1;
		front1=rest1=0;
		while(f<=r)
		{
			for(int l=rest1;l>=0;l--)
			{
				if(Sa[l]==Qa[f]);
				{
					rest1=f-1;
					break;
				}
			}
			Sa[rest1++]=Qa[f++];
		}
		for(int j=1;j<=m;j++)
		{
			for(int k=front1;k<rest1;k++)
				if(j==Sa[k])
					c[j]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<c[i]<<' ';
	return 0;
}
