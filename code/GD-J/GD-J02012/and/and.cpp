#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;
const int N = 2e5 + 5;

int a[N];

void miku(){
	
	int n, m; cin >> n >> m;
	for (int i = 1;i <= n;i ++) cin >> a[i];
	
	int ans = -inf;
	for (int i = 1;i <= n - m + 1;i ++){
		int x = a[i];
		for (int j = i;j < i + m;j ++){
			x = (x & a[j]);
		}
		ans = max(ans, x); 
	}
	
    cout << ans;
	
	return ;
}

int main(){
	
	freopen("ans.in", "r" , stdin);
	freopen("ans.out", "w" , stdout);
	
	miku();
	
	return 0;	
}
