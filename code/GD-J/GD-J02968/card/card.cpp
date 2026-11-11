#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[500005],d[300005],k;
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
		k=i;
		for(int j=i;j<=n;j++)
		{
			c[k]=a[j];
			b[a[j]]++;d[a[j]]++;
			if(b[a[j]]==2)
			{
				for(int l=j-1;l>=i;l++)
				{
					if(c[l]==a[j])
					{
						d[a[j]]--;
						break;
					}
					d[c[l]]--;
				}
			} 
			k++;
			memset(b,0,300005);
		}
	}
	for(int i=1;i<=m;i++) cout<<d[i]<<' ';
	return 0;
}
