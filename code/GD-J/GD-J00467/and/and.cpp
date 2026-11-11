#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N];

int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	if(m == 1){
		long long ans = 0;
		for(int i = 1;i <= n;i ++){
			ans = max(ans,a[i]);
		}
		cout << ans; 
		return 0;
	} 
	else if(n == m){
		long long ans = a[1];
		for(int i = 2;i <= n;i ++){
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	else if(m == 2){
		long long cnt = 0;
		for(int i = 1;i <= n;i ++){
			long long ans = a[i];
			for(int j = i + 1;j <= n;j ++){
				cnt = max(cnt,a[i] ^ a[j]);
			}
		}
		cout << cnt;
		return 0;
	}
	long long zong;
	for(int i = 1;i <= (1 << n);i ++){
		int num = 0,cnt = 0;
		long long ans;
		for(int j = 1;j <= n;j ++){
			if((1 << (j - 1) & i) && cnt == 0){
				cnt ++;
				ans = a[i];
				num ++;
			}
			if((1 << (j - 1) & i) && cnt != 0){
				if(num > m) break; 
				ans &= a[i];
				num ++;
			}
			if(num > m || num < m) continue;
			else zong = max(zong,ans);
		}
	}
	cout << zong;
	return 0;
 } 

