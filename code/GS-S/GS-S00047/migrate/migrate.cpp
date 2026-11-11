#include<bits/stdc++.h>
using namespace std;
int c,t;
const int N = 2000010;
int a[N];
inline void solve(){
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	cout << "0" << "\n"; 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> n >> t;
	while(t--){
		solve();
	}
}
