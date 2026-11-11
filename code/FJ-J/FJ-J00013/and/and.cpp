#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
constexpr int LOGN = 31;

int n,m;
vector<int> a;
unordered_multiset<int> cond;
array<int,LOGN+1> cnt;

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	a.resize(n+1);
	cnt.fill(0);
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		cond.insert(a[i]);
		
		for(int j = 0;j <= LOGN;j++){
			if(a[i] & (1<<j)){
				cnt[j]++;
			}
		}
	}

	int ans = 0;
	for(int i = LOGN;i >= 0;i--){
		if(cnt[i] < m) continue;
		
		vector<int> del;
		for(auto x : cond){
			if(!(x&(1<<i))){
				del.push_back(x);
				for(int j = 0;j <= LOGN;j++){
					if(x & (1<<j)){
						cnt[j]--;
					}
				}
			}
		}
		
		for(auto x : del){
			cond.erase(x);
		}

		ans |= (1<<i);		
	}
	
	cout << ans << endl;

	return 0;
}

