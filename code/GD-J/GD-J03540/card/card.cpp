#include <bits/stdc++.h>
using namespace std;
int n,m,a[500001],t[300001],b[300001];
bool ok[500001],o=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t[a[i]]+=i;
		if(a[i]<a[i-1])o=0;
	}
	if(o)
	{
		for(int i=1;i<=n;i++)
		  if(a[i]!=a[i+1])cout<<i<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[a[i]]==0)b[a[i]]=i;
		else
		{
			cout<<b[a[i]]<<' '<<i<<endl;
			for(int j=b[a[i]];j<i;j++)
			{
				if(!ok[j])
				{
					t[a[j]]-=b[a[i]];
					ok[j]=1;
				}
			}
			b[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++)
	  cout<<t[i]<<' ';
}
