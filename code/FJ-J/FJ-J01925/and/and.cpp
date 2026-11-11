#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,a[N],ans,fans,ch[N];
bool vis[N];
void dfs(int k)
{
	if(k>m)
	{
		fans=ch[1];
		for(int i=2;i<k;i++)
		{
			fans&=ch[i];
		}
		ans=max(ans,fans);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			ch[k]=a[i];
			vis[i]=1;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	//7
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}
	//6
	if(m==1)
	{
		ans=INT_MIN;
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	//Ð¡Êý¾Ý 
	dfs(1);
	cout<<ans;
}
