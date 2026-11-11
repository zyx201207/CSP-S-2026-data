#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
int a[N], cnt[N], last[N], ans[N];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		last[a[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		int tot = i;
		memset(cnt, 0, sizeof(cnt));
		while(tot <= n){
			if(last[a[tot]] != tot)tot = last[a[tot]];
			cnt[a[tot]]++;
			tot++;
		}
		for(int j = 1; j <= m; j++){
			if(cnt[j] > 0)ans[j]++;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	return 0;
}
