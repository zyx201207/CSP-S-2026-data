#include<bits/stdc++.h>
using namespace std;
int n,m,a[500200]={},c[300200];
int b[500200]={};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k=1;
		for(int j=i;j<=n;j++)
		{
			int f=1;
			for(int q=1;q<=k;q++)
			{
				if(b[q]==a[j]) f=0,k=q;
			}
			if(f) b[++k]=a[j];
		}
		for(int j=1;j<=k;j++) c[b[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
}
