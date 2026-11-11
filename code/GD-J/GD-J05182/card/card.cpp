#include<bits/stdc++.h>
using namespace std;

int a[200005];
//,w[900],ans[900],nw
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	if(m == 1)
	{
		cout << n;
		return 0;
	}
	if(m == 2)
	{
		int cnt1 = 0,cnt2 = 0;
		for(int i = 1;i <= n;i++) cin >> a[i];
		for(int i = 1;i <= n - 1;i++)
		{
			int x = a[1],y = 0;
			for(int j = 2;j <= n;j++)
			{
				if(a[j] == y && y != 0) continue;
				else if(a[j] != y && y != 0)
				{
					y = 0;
					x = a[j];
				}
				if(y == 0 && a[j] != x) y = a[j];
			}
			if(x == 1) cnt1++;
			if(y == 1) cnt1++;
			if(x == 2) cnt2++;
			if(y == 2) cnt2++;
		}
		if(a[n] == 1) cnt1++;
		else cnt2++;
		cout << cnt1 << ' ' << cnt2;
		return 0£» 
	}
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i <= n;i++)
//	{
//		memset(w,0,sizeof(w));
//		for(int j = i;j <= n;j++)
//		{
//			nw++;
//			if(w[a[j]] != 0)
//			{
//				for(int k = 1;k <= m;k++)
//				{
//					if(w[k] > w[a[j]])
//					{
//						w[k] = 0;
//						nw--;
//					} 
//				}
//			}
//			w[a[j]] = nw;
//			for(int k = 1;k <= m;k++)
//				if(w[k] > 0) ans[k]++;
//		}
//	}
//	for(int i = 1;i <= m;i++)
//		cout << ans[i] << ' ';
	return 0;
}
