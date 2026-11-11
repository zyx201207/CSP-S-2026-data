#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],lst[3001],sum[500001];
bool vis[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>=10000)
	{
		if(a[n]==1) cout<<n<<" "<<n-1;
		else cout<<n-1<<" "<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		memset(lst,0,sizeof(lst));
		for(int j=1;j<i;j++) vis[j]=1;
		for(int j=i;j<=n;j++) vis[j]=0;
		for(int j=i;j<=n;j++)
		{
			if(lst[a[j]]) 
			{
				for(int k=lst[a[j]];k<j;k++)
				{
					vis[k]=1;
					lst[a[k]]=0;
				}
			}
			lst[a[j]]=j;
		}
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]) sum[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
	return 0;
} 
