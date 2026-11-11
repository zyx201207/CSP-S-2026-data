#include<bits/stdc++.h>
using namespace std;
int n,m,len,a[500001],b[500001],cnt[300001];
bool c[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		len=0;
		memset(c,false,sizeof(c));
		for(int j=i;j<=n;j++)
		{
			if(c[a[j]]==false)
			{
				b[++len]=a[j];
				c[a[j]]=true;
			}
			else
			{
				for(int k=len;k>=1;k--)
				{
					if(b[k]==a[j])
					{
						len=k-1;
						break;
					}
				}
				b[++len]=a[j];
				c[a[j]]=true;
			}
		}
		for(int i=1;i<=len;i++)cnt[b[i]]++;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",cnt[i]);
	return 0;
}
