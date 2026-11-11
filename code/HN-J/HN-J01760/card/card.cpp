#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int a[N];
int b[M];
int s[N];
int n;
int m;
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int hh=i;
		int tt=i-1;
		for(int j=i;j<=n;j++)
		{ 
			for(int k=j;k<=hh;k++)
			{
				if(s[k]==s[j])
				{
					while(tt<=hh)
					{
						s[tt--]=0;
					}
				}
			}
			s[hh++]=s[j];
		}
		for(int j=tt;j<=hh;j++)
		{
			b[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
