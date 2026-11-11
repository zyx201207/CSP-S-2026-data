#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int N  = 5e5 + 5;
int n , m;
int t[N] , xl[N] , w[N];
int ans[N] , a[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	
	for(int i = 1;i <= n;i++)
	{
		
		int x = 0;
		for(int j=0;j<=m;j++)
		w[j]=0;
		for(int j=0;j<=n;j++)
		xl[j]=0;
		for(int j=i;j<=n;j++)
		{
			if(w[a[j]])
			{
				for(int k = w[a[j]]+1;k <= x;k++)
				{
					if(w[xl[k]])
						ans[xl[k]]--;
					w[xl[k]]=0;
				}
				x++;w[a[j]] = x;
			}else
			{
				x++;
				xl[x] = a[j] , w[a[j]] = x;
				ans[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
		cout << ans[i] << ' ';
	return 0;
}

