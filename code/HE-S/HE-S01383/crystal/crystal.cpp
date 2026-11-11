#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read() {
	int x = 0;
	int f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x * f;
}

const int SIZN = 5e5 + 10;

int n,m;
int a[SIZN];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read();
	m = read();
	for(int i = 1 ; i <= n ; i++)a[i] = read();
	sort(a + 1,a+n+1);
	queue<int> q;
	int ans = 0;
	int sums = 0;
	int ps = 0;
	for(int i = 1 ; i <= n ; i++){
		sums += q.size() * (a[i] - a[i - 1]);
		while(!q.empty() && sums > m){
			sums -= a[i] - q.front();
			q.pop();
		}
		q.push(a[i]);
		int t = q.size();
		ans = max(ans,t);
	}
	cout << ans;
	return 0;
}
