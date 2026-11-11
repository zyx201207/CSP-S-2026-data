#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
struct node{
	char ai;
	int ci;
}v[N];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> v[i].ci >> v[i].ai;
	} 
	int ans = 0;
	int i = 1, j = n;
	while(i < j){
		if(v[i].ai == v[j].ai){
			if(v[i].ci == v[j].ci){
				i++, j--;
				continue;
			}else{
				if(v[i].ci > v[j].ci){
					v[i].ci -= v[j].ci;
					j--;
				}else{
					v[j].ci -= v[i].ci;
					i++;
				}
			}
		}else{
			if(v[i].ci == v[j].ci){
				ans += v[i].ci; 
				i++, j--;
				continue;
			}else{
				if(v[i].ci > v[j].ci){
					ans += v[j].ci;
					v[i].ci -= v[j].ci;
					j--;
				}else{
					ans += v[i].ci;
					v[j].ci -= v[i].ci;
					i++;
				}
			}
		}
	}
	cout << ans;
}

/*
2
2 a
3 a


*/
