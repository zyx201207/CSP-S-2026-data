#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[500861];
int l[300861];//qing shu ru wen ben
bool k[500861];
int geshu[300861];
int que[500861];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,tai;
	cin>>n>>m;
	for(int u=1;u<=n;u++)
	cin>>a[u];
	for(int u=1;u<=n;u++)
	{
		memset(l,0,sizeof(l));
		memset(que,0,sizeof(que));
		tai=0;
		for(int p=u;p<=n;p++)
		{
			tai++;
			if(!l[a[p]]||k[l[a[p]]]==true)
			l[a[p]]=tai,que[tai]=a[p];
			else
			{
				for(int i=tai-1;i>l[a[p]];i--)
				l[que[i]]=0;
				tai=l[a[p]],l[a[p]]=tai,que[tai]=a[p];
			}
		}
		for(int p=1;p<=tai;p++)
		if(!k[p])
		geshu[que[p]]++;
	}
	for(int u=1;u<=m;u++)
	cout<<geshu[u]<<' ';
	cout<<endl;
	return 0;
}
