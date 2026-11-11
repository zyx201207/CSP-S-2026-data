#include<bits/stdc++.h>
using namespace std;
long long a[500024];
long long cnt[300024];
long long ans[300024];
long long table[500024];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		long long len = 0;
		memset(cnt, 0, sizeof(cnt));
		memset(table, 0, sizeof(table));
		for (int j = i; j <= n; j++){
			if (cnt[a[j]] == 0){
				cnt[a[j]]++;
				len++;
				table[len] = a[j];
			}else{
				for (int k = len; k >= 1; k--){
					if (table[k] == a[j]){
						len = k;
						break;
					}else{
						cnt[table[k]]--;
					}
				}
			}
		}
		for (int j = 1; j <= len; j++){
			ans[table[j]]++;
		}
	}
	for (int i = 1; i <= m; i++){
		cout << ans[i] << " ";
    }
    cout << endl;
    	
    return 0;
}
