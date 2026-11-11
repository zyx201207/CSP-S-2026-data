#include <bits/stdc++.h>
//#define int long long
using namespace std;
int n , m;
int ans[300005];
int a[300005];
bool f[300005];
int pos[300005];
int cnt = 0;
int v[300005];
bool flag = true;
bool flag1 = true;
int sum[300005];
signed main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
		if(a[i] < a[i - 1]) flag = false;
		sum[a[i]] ++;
		if(a[i] > 2) flag1 = false;
	}
	if(flag == true){
		for(int i = 1 ; i <= m ; i ++){
			sum[i] += sum[i - 1];
			cout << sum[i] << " ";
		}
		cout << "\n";
		return 0;
	}
	else if(flag1 == true){
		for(int i = 1 ; i <= n ; i ++){
			if(a[i] == a[n]) ans[a[i]] ++;
			else ans[1] ++ , ans[2] ++;
		}
		for(int i = 1 ; i <= 2 ; i ++){
			cout << ans[i] << " ";
		}
		cout << "\n";
		return 0;
	}
	for(int i = 1 ; i <= n ; i ++){
		memset(f , false  , sizeof(f));
		memset(pos , 0 , sizeof(pos));
		cnt = 0;
		for(int j = i ; j <= n ; j ++){
			if(f[a[j]] == false){
				v[++ cnt] = a[j];
				pos[a[j]] = cnt;
				f[a[j]] = true;
			}
			else{
				for(int k = pos[a[j]] + 1 ; k <= cnt ; k ++){
					f[v[k]] = false;
					pos[v[k]] = 0;
					v[k] = 0;
				}
				cnt = pos[a[j]];
			}
		}
		for(int j = 1 ; j <= cnt ; j ++){
			ans[v[j]] ++;
		}
	}
	for(int i = 1 ; i <= m ; i ++) cout << ans[i] << " ";
	cout << "\n";
	return 0;
}
/*
16 2
1 1 1 2 2 1 1 1 2 1 2 1 1 2 2 1
*/
