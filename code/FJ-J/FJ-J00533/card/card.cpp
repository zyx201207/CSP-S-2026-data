#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
		if(cnt[a[i]]>1)
		{
			cnt[a[i]]-=2;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<cnt[i]<<' ';
	return 0;
}
