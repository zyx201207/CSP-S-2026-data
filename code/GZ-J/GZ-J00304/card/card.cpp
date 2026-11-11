//GZ-J00304 遵义市播州区南白初级中学 王耀葵  
#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int cnt[300005];
int main(){
	freopen("card.out", "w", stdout);
	freopen("card.in", "r", stdin);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ ){
		cin >> a[i];
	}
	int c = n;
	while(c -- ){
		int l = 1;
		for(int i = n - c + 1; i <= n; i ++ ){
			b[l] = a[i];
			for(int j = 1; j <= i; j ++ ){
				if(b[j] == b[i]){
					for(; j < i; j ++ ){
						b[j] = 0;
					}
					break;
				}
			}
			l ++;
			if(i = n){
				for(int j = n - c + 1; j <= c; j ++ ){
					if(b[j] != 0){
						cnt[b[j]] ++;
					}
				}
			}
		}
	}
	for(int i = 1; i <= m; i ++ ){
		cout << cnt[i] << ' ';
	}
	return 0;
}
