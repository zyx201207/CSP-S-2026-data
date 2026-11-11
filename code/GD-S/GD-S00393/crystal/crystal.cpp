#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 7;
int n;
ll m;
ll a[N];
ll pre[N];
int main(){
	freopen("crystal.in" ,"r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	int ans = 0;
	for(int i = 1, j = 1; i <= n; i++){
		while((i - j + 1) * a[i] - (pre[i] - pre[j - 1]) > m) j++;
		ans = max(ans, i - j + 1); 
	}
	printf("%d\n", ans);
	return 0;
} 
