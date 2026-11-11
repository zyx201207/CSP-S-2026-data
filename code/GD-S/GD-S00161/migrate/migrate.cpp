#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,d;
int a[2000005];
int flag;
int dd[2000005];
void dfs(int l,int r,int cc,int k){
	if(k + 1 == cc){
//		for(int i = 1 ; i < cc ; i ++){
//			cout << dd[i] << " ";
//		}
//		cout << "\n";
		for(int i = 2 ; i < cc ; i ++){
			if(a[dd[i]] - a[dd[i - 1]] > d)return;
		}
		if(dd[cc - 1] != r)return;
		flag ++;
		return;
	}
	if(flag == 2)return;
	for(int i = max(l + 1 , dd[k - 1] + 1) ; i <= r ; i ++){
		if(a[i] - a[dd[k - 1]] <= d){
			dd[k] = i;
			dfs(l , r , cc , k + 1);
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	cin >> c >> T;
	while(T --){
		cin >> n >> d;
		for(int i = 1 ; i <= n ; i ++){
			cin >> a[i];
		}
		if(n <= 9){
			int cnt = 0;
			for(int i = 1 ; i <= n ; i ++){
				for(int j = i + 3 ; j <= n ; j ++){
					int ans = 0,cc = 1;
					for(int k = i + 1 ; k <= j ; k ++){
						ans += a[k] - a[k - 1];
						if(ans > d){
							ans = a[k] - a[k - 1];
							cc ++;
						}
					}
					flag = 0;
					dfs(i , j , cc , 1);
					if(flag >= 2){
						cout << i << " " << j << " " << cc << "\n";
						cnt += (n - j + 1);
						break;
					}
				}
			}
			cout << cnt << "\n";
		}
	}
	return 0;  
}

