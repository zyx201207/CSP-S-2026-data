#include<bits/stdc++.h>
using namespace std;
const int N=5e5,M=3e5;
int n,m,a[N],f[N],sz[N],ls[M],ans[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		sz[i]=1;
		if(ls[a[i]]!=0)
			f[i]=ls[a[i]]+1;
		else
		{
			f[i]=i+1;
			ls[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans[a[i]]+=sz[i];
		sz[f[i]]+=sz[i];
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
