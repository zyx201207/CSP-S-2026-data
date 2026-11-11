#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10; 
long long n, m, ans, a[N], sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i = -~i) cin>>a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1, j = 0;i <= n;i = -~i){
		sum[i] = sum[i - 1] + a[i];
		while(a[i] * (i - j) - (sum[i] - sum[j]) > m) j ++;
		ans = max(ans, 0ll + i - j);
	}
	cout<<ans;
	return 0;
} 
