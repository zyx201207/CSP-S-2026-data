#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, s[500005], distances[500005], qzh[500005], ans[500005];

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n; i++)  cin >> s[i];
	sort(s + 1, s + n + 1);
	for(int i = 1;i <= n; i++){
		if(i > 1)  distances[i] = s[i] - s[i - 1];
		qzh[i] = distances[i] + qzh[i - 1];
	}  
	    
	int sum = 0, now = 1;    
	for(int i = 1;i <= n; i++){
		sum += ((i - now) * distances[i]);
		if(m < sum){
			ans[now] = i - now;
			int rise = 0, yuan = now;
			while(now <= i){
				now++, rise++;
				int tryagin = sum - qzh[i] + qzh[now - 1];
				sum -= qzh[i] - qzh[now - 1];
				if(tryagin <= m){
					break;
				}
			}
		}else if(i == n && m >= sum)  ans[now] = i - now + 1;
	}    
	
	int maxn = -1e18;
	for(int i = 1;i <= n; i++){
		maxn = max(maxn, ans[i]);
	}
	
	cout << maxn;
	
	
	return 0;
} 
