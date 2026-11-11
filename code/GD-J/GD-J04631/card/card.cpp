#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],wz[300010],dq[500010],ans[300010];
bool v[300010];
void dfs(int p,int zps)
{
 if(p>n)
 {
 	for(int i=1;i<=zps;i++)
 	ans[dq[i]]++;
 	return;
 }
 
 if(v[a[p]])
 {
  for(int i=wz[a[p]]+1;i<=zps;i++)
  	v[dq[i]]=false;
  	dfs(p+1,wz[a[p]]);
 }
else
{
 v[a[p]]=true;
 wz[a[p]]=zps+1;
 dq[zps+1]=a[p];
 dfs(p+1,zps+1);	
}	
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
	memset(v,false,sizeof(v));
	dfs(i,0);	
	 } 
	for(int i=1;i<=m;i++)
	cout<<ans[i]<<" ";
	return 0;
}
