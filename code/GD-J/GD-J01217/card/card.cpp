#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10,M=5e3+10,K=1e4+10;
ll n,m,a[N],pre[N],cnt[N],ans[N],res[K];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		for(int i=1;i<=m;i++) res[i]=0,pre[i]=0;
		for(int j=i;j<=n;j++)
		{
//			cnt[a[j]]++;
			res[a[j]]++;
			if(res[a[j]]==2)
			{
//				cout<<1;
				for(int k=pre[a[j]];k<j;k++)
				{
					if(res[a[k]]) res[a[k]]--;
				}
			}
			pre[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
		{
			if(res[j]>0) ans[j]++;
//			cout<<res[j]<<' ';
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
