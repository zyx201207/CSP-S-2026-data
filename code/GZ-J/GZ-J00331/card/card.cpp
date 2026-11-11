//GZ-J00311 贵阳市第三中学 杨鑫豪 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],ans[300005],last[300005];
int main()
{
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
	}
	for(int k=n;k>=1;k--)
	{
		for(int i=1;i<=m;i++)
		{
			last[i]=1;
			b[i]=0;
		}
		for(int i=k;i<=n;i++)
		{
			if(b[i]==0)
			{
				last[a[i]]=i;
				b[i]++;
			}
			else if(b[i]==1)
			{
				last[a[i]]=i;
			}
		}
		for(int i=k;i<=n;i++)
		{
			ans[a[i]]++;
			i=last[a[i]];
		}
	}
	
	for(int i=1;i<=m;i++)
	{
	    printf("%d ",ans[i]);
	}
	return 0;
}
