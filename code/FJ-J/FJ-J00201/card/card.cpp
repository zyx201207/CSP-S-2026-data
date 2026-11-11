#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[500005],p[500005],maxn;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
		{
			if(cnt[a[i]]==0)cnt[a[i]]=n-i+1;
		}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
