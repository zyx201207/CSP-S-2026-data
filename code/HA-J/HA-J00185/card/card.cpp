#include<bits/stdc++.h>
using namespace std;
int num[300030],a[500050];
int main()
{freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m;
cin>>n>>m;
for(int y=1;y<=n;y++)
{scanf("%d",&a[y]);
}
if(n<=5000)
{
	for(int y=1;y<=n;y++)
	{  int aa[n+1],head=1,tail=0;
	memset(aa,0,sizeof(aa));
	 for(int u=y;u<n;u++)
	{aa[tail++]=a[u];
	for(int o=y;o<u;o++)
	 if(aa[o]==aa[u])
	  {
	 for(int v=o;v<u;v++)
	  aa[v]=0;
	  break; }
	}
	for(int u=head;u<=tail;u++)
	if(aa[u]!=0)
	num[aa[u]]++;	
	}
	for(int y=1;y<=m;y++)
	cout<<num[y]<<' ';
}
return 0;
}
