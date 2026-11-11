//GZ-J00564  毕节七星关东辰实验学校  李浩辰

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e6;
ll n, m, a[maxn], l = 1, front = 1, b[maxn];
bool f[maxn];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	while(l <= n){
		for(int i = l; i <= n; i++){
			if(!f[i]) f[i] = true;
			else{
				front = i;
				f[i] = false;
			} 
		}
		for(int i = front; i <= n; i++) b[a[i]]++;
		l++;
	}
	for(int i = 1; i <= m; i++){
		if(i == m) cout << b[i];
		else cout << b[i] << " "; 
	}
	return 0;
}
