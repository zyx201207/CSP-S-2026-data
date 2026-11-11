#include <bits/stdc++.h> 
using namespace std;
int n,t,f[100005],cnt[100005],m[100005],ha[100005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> t;
	int l = 1;
	for (int i = 1;i <= n;i++){
		cin >> f[i];
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = i;j <= n;j++)
		{
			m[l] = f[j];
			cnt[f[j]]++;
			if (cnt[f[j]] > 1){
				for (int k = l;k >= 1;k--){
					if (m[k] == f[j]){
						l = k;
					}
				}
			}
			l++;
		}
		for (int j = 1;j< l;j++)
		{
			ha[m[j]]++;
		}
		l = 1;
		for (int j = 1;j <= t;j++){
			cnt[j] = 0;
		}
	}
	for (int i = 1;i <= t;i++)
	{
		cout << ha[i] << " ";
	}
	return 0;
}