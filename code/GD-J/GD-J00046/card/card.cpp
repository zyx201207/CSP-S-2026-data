#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],lst[300005],ntw[500005],w,ans[300005];
int main()
{
	cin.tie(0),ios::sync_with_stdio(false);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i],lst[a[i]]=i;
	for(long long i=1;i<=n;i++) ntw[i]=lst[a[i]];
	for(long long i=1;i<=n;i++)
	{
		w=i;
		while(w<=n)
		{
			ans[a[w]]++;
			if(ntw[w]!=w) w=ntw[w]+1;
			else w++;
		}
	}
	for(long long i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
