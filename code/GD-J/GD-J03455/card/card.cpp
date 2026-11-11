#include<bits/stdc++.h>
using namespace std;
int a[200000];
int is[200000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		is[a[i]]+=1;
		if(is[a[i]]>1)
		{
			is[a[i]]=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<(is[i]+i-1)<<" ";
	}
	return 0;
}
