#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

int n,m,b[500010],a[500010];
int main()
{
		freopen("card1.in","r",stdin);
		freopen("card1.answer","w",stdout);
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
				int x[500010],ans[300010],t[500010];
				memset(ans,0,sizeof(ans));memset(t,0,sizeof(t));memset(x,0,sizeof(x));
				for(int j=i;j<=n;j++)
				{
						if(t[a[j]]==0)  {t[a[j]]++;x[a[j]]=j;ans[j]=a[j];}
						else {
							for(int k=x[a[j]];k<=j-1;k++)
							{
									ans[k]=0;
									t[a[k]]=0;
							}
							ans[x[a[j]]]=a[j];
							x[a[j]]=j;
						}
				}
				for(int j=i;j<=n;j++) if(ans[j]!=0) b[ans[j]]++;
		}
		for(int i=1;i<=m;i++) printf("%d ",b[i]);
		return 0;
}

