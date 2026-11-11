#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+7, M = 3e5+7;
int a[N];
int v[N];
int ans[M];
int lenn = 0;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n,m; cin >> n >> m;
	for(int i = 1; i <= n ; i++) cin >> a[i];
	if(n <= 500){
		for(int i = 1; i <= n; i++){
			memset(v,0,sizeof(v));
			lenn = 0;
			for(int j = i; j <= n; j++){
				int x = a[j];
				bool tt = true;
				for(int k = 1; k <= lenn; k++){
					if(v[k] == x){
						tt = false;
						for(int kk = k; kk <= lenn; kk++) v[kk] = 0;
						lenn = k;
						v[k] =  x;
						break;
					}
				}
				if(tt){
					lenn++;
					v[lenn] = x;
				}
			}
			for(int j = 1; j <= lenn; j++){
				ans[v[j]]++;
			} 
		}
		for(int i = 1; i <= m; i++)cout << ans[i] << " ";
	}else{
		
	}
	return 0;
}
/*
4 3
1 2 1 3
*/
