#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2000005;

int c, n, m, t, q;
int x[N] = {};



int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	
	
	int ans = 10;
	cin >> c >> t;
	while (t--){
		
		for (int i = 1; i <= n; i++)	cin >> x[i];
		
		cout <<ans<<endl;
		ans-=2;
		
	}
	return 0;
	
	
	
}
