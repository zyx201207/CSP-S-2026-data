#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],b[100001],c[100001],minn=9999999,minnn,p;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){cin>>a[i];b[i]=a[i];}
	for(int z=0;z<n;z++)
	{
		p=0,minn=9999999;
		for(int i=0;i<n;i++)b[i]=a[i];
		for(int i=z;i<n;i++)
		{

			for(int j=i+1;j<n;j++)
			{
				if(a[i]==a[j])
				{
					if(j-i<minn)
					{
						minn=j-i;
						p=j;
					}
				}
			}
			for(int v=0;v<p;v++)b[v]=0;
		}
		for(int i=z;i<n;i++)
		{
			if(b[i]!=0)c[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
}
