#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=5e5+10;
int n,m,a[N],ans[N],st[N],tt=0,cnt[M],f[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		f[cnt[a[i]]]=i;
		cnt[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int k=i;
		while(k<=n)
		{
			ans[a[k]]++;
			while(f[k]!=0 and k<=n)k=f[k];
			k++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
