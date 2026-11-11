#include <bits/stdc++.h>

using namespace std;

#define int long long
#define SIZE 10005
int tot,n,m;
int a[SIZE],last[SIZE],ve[SIZE],ans[SIZE];
bool vis[SIZE];
signed main ()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m ;
	
	for (int i=1;i<=n;++i)
		cin >> a[i] ;
		
	for (int i=1;i<=n;++i)
	{
		memset(vis,false,sizeof(vis));
		tot=0;
		for (int o=i;o<=n;++o)
		{
			if (vis[a[o]])
			{
				if (tot<last[a[o]])
				{
					last[a[o]]=++tot;
					ve[tot]=a[o];
				} else {
					tot=last[a[o]];
					ve[tot]=a[o];
				}
			} else {
				vis[a[o]]=true;
				ve[++tot]=a[o];
				last[a[o]]=tot;	
			}
		} 
		
		for (int o=1;o<=tot;++o)
		{
			ans[ve[o]]++;
		}
	}
	
	for (int i=1;i<=m;++i)
		cout << ans[i] << ' ' ;	
	
	return 0;
}
