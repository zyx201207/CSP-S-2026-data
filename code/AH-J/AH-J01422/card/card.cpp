#include<bits/stdc++.h>
using namespace std;
int a[500000],t[300000],f[300000],h[500000];
int main(){
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
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]==0)
			{
				f[a[j]]=1;
				h[j]=a[j];
			}
			else
			{
				for(int z=j+1;z<=n;z++)
				{
					h[j]=0;
				}
			}
		}
		for(int j=i;j<=n;j++)
		{
			 t[h[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
	return 0;
}
