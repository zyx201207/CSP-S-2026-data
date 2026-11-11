//+eraby+e connec+10n!
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5+5;
int n,m,a[maxn];
int lvis[maxn];
int rev[maxn],dep[maxn],cnt[maxn],ans[maxn];
signed main(){
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	memset(lvis,-1,sizeof(lvis));
	
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int i = n;i >= 1;i--){
		if (lvis[a[i]] >= 0){
			rev[i] = lvis[a[i]];
			dep[i] = dep[rev[i]];
			cnt[dep[i]]++;
		}else{
			rev[i] = -1;
			dep[i] = i;
			cnt[i]++;
		}
		lvis[a[i]] = i;
	}
//	for (int i = 1;i <= n;i++){
//		cout << rev[i] << ' ' << dep[i] << '\n';
//	}cout << '\n';
	for (int i = 1;i <= n;i++){
		ans[a[i]] += cnt[i];
		cnt[dep[i+1]] += cnt[i];
	}
	for (int i = 1;i <= m;i++){
		cout << ans[i] << ' ';
	}
} 
