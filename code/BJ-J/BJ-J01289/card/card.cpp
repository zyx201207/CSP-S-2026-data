#include <iostream>
using namespace std;

long long n,m,a[500005],h[300005],g[300005],b[500005],k=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			h[j]=0;
		}
		for(int j=1;j<=k;j++)
		{
			b[j]=0;
		}
		k=1;
		for(int j=i;j<=n;j++)
		{
			if(h[a[j]]==0)
			{
				b[k]=a[j];
				k++;
				h[a[j]]=j;
			}
			else
			{
				for(int z=h[a[j]]+1;z<=j-1;z++)
				{
					h[b[z]]=0;
					b[z]=0;
				}
				k=h[a[j]]+1;
			}
		}
		k--;
		for(int j=1;j<=k;j++)
		{
			g[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<g[i]<<" ";
	}
	return 0;
}
