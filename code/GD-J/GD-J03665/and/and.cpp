#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int a[MAXN];
int ma=-1e-5;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=0;i<n;i++)
		{
			ma=max(ma,a[i]);
		}
		cout<<ma;
	}
	else if(m==2)
	{
		for(int i=n-1;i>0;i--)
		{
			for(int j=0;j<i;j++)
			{
				ma=max(ma,(a[j]&a[j+1]));
			}
		} 
		cout<<ma;
	}
	else if(m==3)
	{
		for(int i=n-1;i>0;i--)
		{
			for(int j=n-2;j>0;j--)
			{
				for(int k=0;k<j;k++)
				{
					ma=max(ma,(a[j]&a[j+1]&a[j+2]));
				} 
				
			}
		} 
		cout<<ma;
	}
	return 0;
}
