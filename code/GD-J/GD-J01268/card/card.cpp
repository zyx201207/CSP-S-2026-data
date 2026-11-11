#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[300005],l;
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
		vector<int> la;
		la.push_back(i-1);
		for(int j=1;j<=m;j++)
		{
			b[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]>0)
			{
				la.push_back(b[a[j]]);
				la.push_back(l-1);
			}
			b[a[j]]=j;
		}
		la.push_back(n+1);
		for(int j=0;j<int(la.size());j+=2)
		{
			for(int k=la[j]+1;k<=la[j+1]-1;k++)
			{
				c[a[k]]++;	
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
} 
