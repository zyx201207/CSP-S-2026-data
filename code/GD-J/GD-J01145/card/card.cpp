#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[300005],d[300005];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			b[a[j]]++;
			if(c[a[j]]!=0)
			{
				for(int k=c[a[j]];k<j;k++)
				{
					b[a[k]]=max(0,b[a[k]]-1),c[a[k]]=0;
				}
			}
			c[a[j]]=j;
		}
		for(int j=1;j<=m;j++) 
		{
			if(b[j]>=1) d[j]++;
			b[j]=0,c[j]=0;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",d[i]);
	return 0;
}
