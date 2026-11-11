#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;
int n,m,sum;
int a[N];
map<int,int> mp;
signed main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin >> n >> m;
	for(int i = 1;i <= n;i ++ ){
		cin >> a[i];
		mp[a[i]] ++ ;
	}
	int maxn = -0x3f3f3f3f;
	for(auto m : mp){
		maxn = max(maxn,m.second);
	}		
	sort(a + 1,a + 1 + n);
	if(maxn == 1){
		sum = a[(n + 1) / 2];
	}else{
		for(int i = 1;i <= n;i ++ ){
			if(mp[a[i]] == maxn){
				sum = a[i];
				break;	
			}
		}
	}
	int ans = 1;
	int beginn = lower_bound(a + 1,a + 1 + n,sum) - a;
	int endd = upper_bound(a + 1,a + 1 + n,sum) - a - 1;
	if(beginn <= m){
		for(int i = 1;i <= n;i ++ ){
			if(m >= (sum - a[i]) && sum >= a[i]){
				m = m - (sum - a[i]);
				ans ++ ;
			}
		}
		if(m != 0){
			for(int i = 1;m > 0;i ++ ){
				int shiya = sum,sans = ans;
				if(m >= endd) m -= endd;
				else if(mp[shiya + i] == 0) break;
				if(mp[shiya + i] == 0) continue; 
				if(endd <= m){
					m -= endd;
					shiya += i;
				}else{
					for(int j = endd;j >= m;j ++ ){
						shiya ++ ;
					}
					m = 0;
					sans = sans - (endd - m);
				}
				sans += mp[shiya];
				endd += mp[shiya];
				ans = max(sans,ans);
			}
		}
	}
	cout << ans;
	return 0;
}/*

5 6
-1 -1 -1 1 6
6 - 3 = 3
ans = 3
0 0 0 1 6
ans = 4;
if(endd <= m){
					m -= endd;
					shiya += i;
				}else{
					for(int j = endd;j >= m;j ++ ){
						shiya ++ ;
					}
					m = 0;
					sans = sans - (endd - m);
				}
				for(int i = endd + 1;i <= n;i ++ ){
					if(shiya == a[i]){
						sans ++ ;
					}
				}
				ans = max(sans,ans);
*/
