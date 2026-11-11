#include<bits/stdc++.h>
using namespace std;
int a[10000005],temp[500005],s[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int w=1;
		for(int j=i;j<=n;j++)
		{
			temp[w++]=a[j];
			if(temp[w-2]==a[j]) w--;
		}
		for(int j=1;j<w;j++)
		{
			s[temp[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<" ";
	} 
	return 0;
	return 0;
}

