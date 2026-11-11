#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int ans,n,m,cnt[20005],k;
int ad[20005];
bool book[20005];
void dfs(int x, int d)
{
	if(d == m)
	{
		ans = max(ans,cnt[k]);
		return;
	}
	for (int i = x+1; i <= n;i++)
	{
		if(!book[i])
		{
			book[i] = true;
			++k;
			cnt[k] = cnt[k-1] & ad[i];
			dfs(i,d+1);
			book[i] = false;
			--k;
		}
		
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 0; i< n;i++)
    {
		cin >> ad[i];
	}
	if(n == m)
	{
		int t = ad[0];
		for(int i = 1; i < n;i++)
		{
			t &= ad[i];
		}
		cout<<t;
		return 0;
	}
	if(n - 1 == m)
	{
		for(int i = 0; i < n;i++)
		{
			int t,w;
			if(i == 0)
			{
				t = ad[n - 1];
				w = n-1;
			}else
			{
				t = ad[i - 1];
				w= i-1;
			}
			for(int j = 0; j < n;j++)
			{

				if(j!=i||j!=w)
				{
					t &= ad[j];
				}
			}
			ans = max(ans,t);
		}
		cout<<ans;
		return 0;
	}
	for(int i = 0; i< n;i++)
    {
		k = 0;
		cnt[0] = ad[i];
		dfs(i,1);
	}
	cout << ans;
    return 0;
}
