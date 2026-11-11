#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 2e6 + 10;
int a[N], n, d, L[N], R[N], sl[N], sr[N];
vector<int> vecl[N], vecr[N];
void solve(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		int tl = 1, tr = i; L[i] = i;
		while(tl <= tr){
			int tm = (tl + tr) / 2;
			if(a[i] - a[tm] <= d) L[i] = tm, tr = tm - 1;
			else tl = tm + 1;
		}
		if(L[i] != i) vecl[L[i]].push_back(i);
	}
	for(int i = 1; i <= n; i++){
		int tl = i, tr = n; R[i] = i;
		while(tl <= tr){
			int tm = (tl + tr) / 2;
			if(a[tm] - a[i] <= d) R[i] = tm, tl = tm + 1;
			else tr = tm - 1;
		}
		if(R[i] != i) vecr[R[i]].push_back(i);
	}	
	for(int i = 1; i <= n; i++) sl[i] = sr[i] = 1;
	for(int i = 1; i < n; i++)
		sl[R[i]] += sl[i];
	for(int i = n; i > 1; i--)
		sr[L[i]] += sr[i];	
	
	int ans = 0;
	int ans2 = 0;
//	for(int i = 1; i <= n; i++) cout << i << " " << L[i] << " - " << R[i] << " " << sl[i] << " " << sr[i] << endl;
	for(int i = 1; i < n; i++){
		int suml = 0, sumr = 0, cntl = 0, cntr = 0;
		int mip = n, mxp = 0, xx, x2;
//		cout << " I : " << i << endl;
		for(auto v : vecr[i + 1]){
			if(v < i){
//				cout << " l : " << v << endl; 
				suml += sl[v];
				cntl++;
				xx = v;
				mxp = max(mxp, v);
			}
				
		} 
		for(auto v : vecl[i]){
			if(v > i + 1){
				x2 = v;
//				cout << " r : " << v << endl; 
				cntr++;
				sumr += sr[v];
				mip = min(mip, v);
			}
				
		} 

//		if(sumr > (n - mip + 1)) cout << "No\n";
//		if(suml > mxp) cout << "No\n";
		if(cntl == cntr && cntr == 1){
			ans += suml * sumr;
		}else if(cntl == 1 && cntr != 1){
			ans += suml * cntr;
		}else if(cntr == 1 && cntl != 1){
			ans += sumr * cntl;
		}else{
			ans += cntl * cntr;
		}
//		cout << ans << endl;
		if(cntl && cntr ) ans2 += sr[mip] * sl[mxp];
//		ans += cntl * sumr + cntr * suml;
	}	
	cout << ans << endl;
	for(int i = 1; i <= n; i++) L[i] = R[i] = 0, vecl[i].clear(), vecr[i].clear(), sl[i] = sr[i] = 0;
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	cin >> T;
	while(T--) solve();
}
