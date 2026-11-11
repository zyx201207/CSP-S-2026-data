#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500010], ans[300010], mp[300010];
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n<=5000&&m<=3000){
		for(int i = 1; i <= n; i++){
			int cnt=0;
			memset(mp, 0, sizeof(mp));
			vector<int> vec(m+3);
			for(int j = i; j <= n; j++){
				if(mp[a[j]]==0||mp[a[j]]>cnt){
					cnt++;
					vec[cnt]=a[j];
					mp[a[j]]=cnt;
				}else{
//					cout << "111" << " " << j << " " << mp[a[j]] << "\n";
					cnt=mp[a[j]];
				}
			}
			for(int j = 1; j <= cnt; j++){
				ans[vec[j]]++;
//				cout << vec[j] << " ";
			}
//			cout << "\n";
		}
		for(int i = 1; i <= m; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
	}else{
		for(int i = 1; i <= n; i++){
			ans[a[i]]=i;
		}
		for(int i = 1; i <= m; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
3 1
1
2 1
1
3 1
2 1
3 1
2 1
1
*/
