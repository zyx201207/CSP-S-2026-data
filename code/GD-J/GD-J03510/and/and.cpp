#include <bits/stdc++.h>
using namespace std;

int n, m, mn5 = 1;
long long a[200005];
long long ans1 = LLONG_MIN, ans2 = LLONG_MIN, ans3, ans4, ans5 = -1, ans6;
vector<long long> chs;

void dfs(int d){
	if (d > n){
		if (chs.size() != m) return;
		
		if (chs.size() == 0){
			ans1 = max(ans1,0ll);
			return;
		}
		
		long long sum = chs[0];
		for (long long &x : chs) sum &= x;
		ans1 = max(ans1,sum);
		return;
	}
	
	chs.push_back(a[d]);
	dfs(d+1);
	chs.pop_back();
	dfs(d+1);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> m;
	
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		
		ans2 = max(ans2,a[i]);
		
		if (i == 1) ans3 = a[i];
		ans3 &= a[i];
		
		if (a[i] < a[mn5]) mn5 = i;
	}
	
	if (n <= 20){
		dfs(1);
		cout << ans1 << '\n';
	}
	else if (m == 1){
		cout << ans2 << '\n';
	}
	else if (m == n){
		cout << ans3 << '\n';
	}
	else if (m == 2){
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= n;j++){
				if (i >= j) continue;
				ans4 = max(ans4,a[i]&a[j]);
			}
		}
		cout << ans4 << '\n';
	}
	else if (m == n-1){
		for (int i = 1;i <= n;i++){
			if (i == mn5) continue;
			if (ans5 == -1) ans5 = a[i];
			ans5 &= a[i];
		}
		cout << ans5 << '\n';
	}
	else if (n > 2000){
		sort(a+1,a+n+1,greater<long long>());
		for (int i = 1;i <= m;i++){
			if (i == 1) ans6 = a[i];
			ans6 &= a[i];
		}
		cout << ans6 << '\n';
	}
	
	return 0;
}
