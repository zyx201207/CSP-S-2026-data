#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx=-1;
bool vis[200005];
void d(int ans,int st)
{
	if(st>m-2)
	{
		maxx=max(maxx,ans);
	 } 
	 for(int i=1;i<=n;i++)
	 {
	 	if(vis[i]==false)
	 	{
	 		vis[i]=true;
	 		d((ans&a[i]),st+1);
	 		vis[i]=false;
		 }
	 }
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		vis[i]=true;
		d(a[i],0);
		vis[i]=false;
	}
	cout<<maxx;
	return 0;
}
