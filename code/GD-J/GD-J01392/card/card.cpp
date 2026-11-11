#include<bits/stdc++.h>
using namespace std;
#define N 500010
int a[N],ed[N],to[N],ans[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)ed[a[i]]=i;
	for(int i=1;i<=n;i++)to[i]=ed[a[i]];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			j=to[j];
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
