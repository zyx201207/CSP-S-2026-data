#include<bits/stdc++.h>
using namespace std;

int a[500005] = {};
int t[500005] = {};
int ans[300005] = {};

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		t[a[i]]++;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int k = n;k >= i;k--)
		{
			
			if(t[k] > 1)
			{
				break;
			}
			ans[a[k]]++;
		}
		t[a[i]]--;
	}
	for(int i = 1;i <= m;i++)
		cout << ans[i] << " ";
	return 0;
}
