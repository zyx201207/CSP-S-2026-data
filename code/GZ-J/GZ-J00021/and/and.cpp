//GZ-J00021 贵阳市第一中学  郑淇予
#include<bits/stdc++.h>
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define ll long long
using namespace std;
const int N = 200005, L = 32;
int cnt[L], a[N];
bool vis[N];
vector<int> vc[L];
//4*2e5*30 = 24e6 = 24MB

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	FOR(i, 1, n){
		cin >> a[i];
		FOR(j, 0, L-1){
			if(a[i]>>j&1){
				cnt[j]++;
			}
			else{
				vc[j].push_back(i);
			}
		}
		//lis[i] = {a[i], i+1};
	}
	//lis[n].next = 0;
	//FOR(j, 0, L-1)if(cnt[j])cout << j << '#' << cnt[j] << endl;
	int ans = 0;
	for(int j = L-1; ~j; j--){
		if(cnt[j] < m)continue;
		ans += 1<<j;
		for(int i : vc[j]){
			if(vis[i] || (a[i]>>j&1))continue;
			FOR(k, 0, j-1){
				if(a[i]>>k&1){
					cnt[k]--;
				}
			}
			vis[i] = true;
		}
	}
	cout << ans;
	return 0;
}
//O(n*l^2) = 2e5*30*30 = 2e8
