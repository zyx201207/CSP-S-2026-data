#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m,a[500005],k,ans[300005],f[300005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof f);
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]])
			{
				for(int z=f[a[j]]+1;z<=j-1;z++)
				{
					f[a[z]]=0;
				}
			}
			f[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
		{
			if(f[j])
			{
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
