#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5;
int n,m,a[M],pos[M],arr[M],ans[M];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>a[i];
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++) pos[j]=-1;
		int now=0;
		for (int j=i; j<=n; j++)
		{
			if (pos[a[j]]==-1)
			{
				arr[++now]=a[j];
				pos[a[j]]=now;
				continue;
			}
			for (int k=now; k>pos[a[j]]; k--) pos[arr[k]]=-1;
			now=pos[a[j]];
		}
		for (int i=1; i<=now; i++)
		{
			ans[arr[i]]++;
		}
	}
	for (int i=1; i<=m; i++) cout<<ans[i]<<' ';
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
