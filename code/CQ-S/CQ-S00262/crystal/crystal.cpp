#include<bits/stdc++.h>
using namespace std;

long long n, m;
long long a[600005];
long long pre[600005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	for(long long i = 1; i <= n; i++){
		pre[i] = pre[i - 1] + a[i];
	}
	
	long long ans1 = 0;
	
	for(long long i = 1; i <= n; i++){
		long long l = 1;
		long long r = i;
		
		while(l < r){
			long long mid = (l + r) / 2;
			long long len = i - mid + 1;
			
			if(len * a[i] - (pre[i] - pre[mid - 1]) <= m){
				r = mid;
			}else{
				l = mid + 1;
			}
		}
		
		ans1 = max(ans1, i - l + 1);
	}
	
	cout << ans1;
	
	return 0;
}

/*


5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
