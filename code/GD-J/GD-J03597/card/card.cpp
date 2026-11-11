#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m;
	cin >> n >> m;
	
	vector<int>s(n + 1);
	vector<vector<int>>r(n + 1); 
	for(int i = 1;i <= n;i++){
		cin >> s[i];
		r[s[i]].push_back(i);
	}
	
	vector<int>t(m + 1);
	vector<int>ans(m + 1);
	for(int i = 1;i <= n;i++){
		
		map<int,int>mp;
		vector<bool>vis(m + 1,false);
		for(int j = i;j <= n;j++){
			if(mp[s[j]] > 0 and vis[s[r[s[j]][(t[s[j]] + mp[s[j]] - 1)]]] == true){
				for(int k = (r[s[j]][(t[s[j]] + mp[s[j]] - 1)] + 1);k < j;k++){
					vis[s[k]] = false;
				}
			}
			
			vis[s[j]] = true;
			mp[s[j]]++;
		}
		for(int j = 1;j <= m;j++){
			ans[j] += vis[j];
		}
		
		t[s[i]]++;
	}
	
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	
	return;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int T = 1;
	while(T--){
		solve();
	}
	return 0;
}
