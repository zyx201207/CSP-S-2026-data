#include<bits/stdc++.h>
using namespace std;
#define int long long
#define debug(n) cout << #n << " = " << n << "\n";
#define deb(n) cout << #n << " = " << n << "    ";
#define div() cout << "\n---------------------\n";
int n,m;
int a[500005];
int cnt[300005];
int ans[300005];
inline void worksmall(){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cnt[j] = 0;
		}
		for(int j = i;j <= n;j++){
			if(!cnt[a[j]]){
				cnt[a[j]] = j;
			}
			else{
				for(int k = cnt[a[j]];k < j;k++){
					cnt[a[k]] = 0;
				}
				cnt[a[j]] = j;
			}
		}
		for(int j = 1;j <= m;j++){
			if(cnt[j]){
				ans[j]++;
			}
		}
	}
	for(int i = 1;i < m;i++){
		cout << ans[i] << " ";
	}
	cout << ans[m];
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n <= 500){
		worksmall();return 0;
	}
	for(int i = 1;i < m;i++){
		cout << n << " ";
	}
	cout << n;
	return 0;
}
