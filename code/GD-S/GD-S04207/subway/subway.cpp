#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[1005],k[505],s[1005][1005],l[1005],le[1005],x,y;//n是边，m是点，d是一点上有几边，q是询问次数
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d%d",&l[j],&le[j]);
			for(int kk=1;kk<j;kk++)
			{
				if(s[l[kk]][l[j]]==0||s[l[kk]][l[j]]>le[j]+le[kk])
				{
					s[l[kk]][l[j]]=le[j]+le[kk];
					s[l[j]][l[kk]]=s[l[kk]][l[j]];
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=m;k++)
			{
				if(j!=i&&k!=i&&j!=k&&(s[j][k]==0||s[j][k]>s[i][j]+s[i][k])&&s[j][i]>0&&s[i][k]>0)
				{
					s[j][k]=s[i][j]+s[i][k];
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",a[x]+a[y]+s[x][y]);
	}
	return 0;
}
