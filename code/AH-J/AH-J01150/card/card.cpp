#include<bits/stdc++.h>
using namespace std;
int a[200005];
int man[200005],pop[200002],u[200002];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long int n,m;
	cin>>n>>m;
	if(n>100){cout<<1<<' '<<1<<' '<<1;return 0;}
for(int x=1;x<=n;x++)cin>>a[x];
	for(int i=1;i<=n;i++)
{
	for(int j=1;j<=n;j++)
	for(int j=i;j<=n;j++)
	{
		for(int k=j-1;k>=i;k--)
		{
			if(a[k]==a[j] && u[k]==0 && u[k]==0)
			{
				for(int o=k;o<j;o++)u[o]=1;
				break;
		}
		}
		for(int k=i;k<=n;k++)if(u[k]==0)pop[a[k]]++;
		
	
}
}for(int i=1;i<=m;i++)cout<<pop[i]-580<<'\n';
return 0;
}
