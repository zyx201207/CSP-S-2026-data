#include <bits/stdc++.h> 
using namespace std;
const int N = 2e5 + 10; 
typedef long long ll;
ll a[N], pre[N];
bool cmp(int a, int b) { 
     return a > b;
}
int main(){
	//freopen("and.in", "r", stdin);
	//freopen("and.out", "w", stdout);
	int n, m; cin >> n >> m;
	pre[0] = 1;
	for(int i = 1; i <= n; i++){
	 cin >> a[i];
	 pre[i] = pre[i - 1] & a[i];
}
    if(n == m){
    	cout << pre[n];
    	return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	cout << a[m];
	return 0;
}
