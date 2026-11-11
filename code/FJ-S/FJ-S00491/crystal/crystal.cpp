#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,num[500005],sum[500005],m,ans = 1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> num[i];
	}
	sort(num + 1,num + n + 1);
	for(int i = 1 ; i <= n ; i++){
		sum[i] = num[i] + sum[i - 1];
	}
	ll tail = 1,head = 1;
	while(tail <= n){
		while(head < tail && (tail - head) * num[tail] - (sum[tail - 1] - sum[head - 1]) > m){
			head++;
		}
		ans = max(ans,tail - head + 1);
		tail++;
	}
	cout << ans;
	return 0;
}
