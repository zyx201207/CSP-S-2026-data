#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
constexpr int LOGN = 21;

int n,m;
vector<int> a;
vector<int> ans;
vector<int> cnt;
vector<int> last;
vector<array<int,LOGN+1>> nxt;

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	a.resize(n+1,0);
	cnt.resize(m+1,0);
	ans.resize(m+1,0);
	nxt.resize(n+1);
	bool subtaskA = true;
	last.clear();
	last.resize(m+1,-1);
	
	for(int i = 1;i <= n;i++){
		nxt[i].fill(INT_MAX);
	}
	
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		cnt[a[i]]++;
		
		if(last[a[i]] != -1){
			nxt[last[a[i]]][0] = i;
		}
		last[a[i]] = i;
		
		if(a[i] < a[i-1]){
			subtaskA = false;
		}
	}
	
	for(int j = 1;j <= LOGN;j++){
		for(int i = 1;i <= n;i++){
			if(nxt[i][j-1] > n) continue;
			nxt[i][j] = nxt[nxt[i][j-1]][j-1];
		}
	}
	
	if(subtaskA){
		for(int i = 1;i <= m;i++){
			cnt[i] += cnt[i-1];
			cout << cnt[i] << " ";
		}
		cout << endl;
		
		return 0;
	}
	
	for(int i = 1;i <= n;i++){
		int j = i;
		while(j <= n){
			for(int k = LOGN;k >= 0;k--){
				if(nxt[j][k] == INT_MAX) continue;
				j = nxt[j][k];
			}
			
			ans[a[j]]++;
			j++;
		}
	}
	
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}

