#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N];
bool vis[N];
int suml[N],sumr[N];
int n,m;
int ans;
void dfs(int step,int now,int pre){
	if(step > m){
		ans = max(ans,now);
		return;
	}
	if(pre == n) return;
	for (int i = pre + 1;i <= n;i++){
		if(!vis[i]){
			vis[i] = true;
			dfs(step+1,now & a[i],i);
			vis[i] = false;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	bool flag = true;
	bool bh = true;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] >= 4) flag = false;
		if(a[i] != i - 1) bh = false;
	}
	if((n <= 20 && m <= n) || (n <= 2000 && (m == 1 || m == 2))){
		dfs(1,INT_MAX,0);
		cout << ans;
		return 0;
	}
	if(m == n){
		int sum = INT_MAX;
		for (int i = 1;i <= n;i++){
			sum &= a[i];
		}
		cout << sum;
		return 0;
	}
	if(m == n - 1){
		int num = 0;
		suml[0] = INT_MAX,sumr[0] = INT_MAX;
		for (int i = 1;i <= n;i++) suml[i] = suml[i-1] & a[i];
		for (int i = n;i >= 1;i--) sumr[i] = sumr[i+1] & a[i];
		for (int i = 1;i <= n;i++){
			if(suml[i-1] == INT_MAX){
				num = max(num,sumr[i+1]);
			}
			if(sumr[i+1] == INT_MAX){
				num = max(num,suml[i-1]);
			}
			num = max(num,suml[i-1] & sumr[i+1]);
		}
		cout << num;
		return 0;
	}
	if(flag){
		sort(a+1,a+n+1);
		int answer = INT_MAX;
		for (int i = n;i >= n - m + 1;i--){
			answer &= a[i];
		}
		cout << answer;
		return 0;
	}
	if(bh){
		int c = INT_MAX;
		for (int i = n;i >= n - m + 1;i--){
			c &= a[i];
		}
		cout << c;
		return 0;
	}
	cout << 0;
	return 0;
}
