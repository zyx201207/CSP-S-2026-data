#include<bits/stdc++.h>
using namespace std;
long long n,m,i,a[500001],j,cun[300001],zhu[500001],top=0,sh=1,ke[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++,top=0,sh=i,memset(ke,0,sizeof(ke)))
	{
		while(sh<=n)
		{
			if(ke[a[sh]])
			{
				for(j=top;j>ke[a[sh]];j--)ke[zhu[j]]=0;
				top=ke[a[sh]];
			}
			else 
			{
				zhu[++top]=a[sh];
				ke[a[sh]]=top;
			}
			sh++;
		}
		for(j=1;j<=top;j++)cun[zhu[j]]++;
	}
	for(i=1;i<=m;i++)cout<<cun[i]<<" ";
	return 0;
}
