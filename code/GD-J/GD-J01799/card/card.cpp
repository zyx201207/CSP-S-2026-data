#include <bits/stdc++.h>
using namespace std;
int ret[300010],t[300010];
int a[500010],b[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	int len = 0;
	for(int i = 1;i <= n;i++)
	{
		len = 0;
		for(int j = 1;j <= m;j++)t[j] = 0;
		for(int j = i;j <= n;j++)
		{
			if(t[a[j]] == 0)
			{
				b[++len] = a[j];
				t[a[j]] = len;
			}
			else
			{
				int x = t[a[j]];
				while(len >= x)
				{
					t[b[len]] = 0;
					len--;
				}
				b[++len] = a[j];
				t[a[j]] = len;
			}
		}
		for(int j = 1;j <= len;j++)ret[b[j]]++;
	}
	for(int i = 1;i <= m;i++)cout << ret[i] << " ";
	return 0;
}
