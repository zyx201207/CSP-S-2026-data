#include<bits/stdc++.h>
using namespace std;
int b[500000];
int main()
{
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int n,m;
	int a[500000];
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		cin>>a[i];
	}
	while(n--)
	{
		for(int i=0;i<n;i++)
		{
			b[a[i]]++;
		}
	}
	for(int i=0;i<m;i++)
	{
		if(b[i]!=0)
		{
			cout<<b[i]<<" ";
		}
	}
	return 0;
}
