#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 2e5 + 100;
int a[N];
int bitcs[N];
int bitcnt(int v){
	int res = 0;
	while(v){
		res += v & 1;
		v >>= 1;
	}
	return res;
}
int dans = 0;
int n, m;
vector<int> choose;
void dfs(int k){
	if(choose.size() == m){
		int v = choose[0];
		for(int i = 1; i < choose.size(); i++){
			v &= choose[i];
		}
		dans = max(v, dans);
	}
	if(k > n) return;
	
	dfs(k+1);
	choose.push_back(a[k]);
	dfs(k+1);
	choose.pop_back();
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i = 1; i < N; i++) bitcs[i] = bitcnt(i);

	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1, [](const int& a, const int& b){
		if(bitcs[a] != bitcs[b]) return bitcs[a] > bitcs[b]; 
		return a > b;
	});
	int ans = -1;
	if(m == 1){
		for(int i = 1; i <= n; i++)
			ans = max(ans, a[i]);
	}
	else if(m == 2){
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				ans = max(ans, a[i] & a[j]);
			}
		}
	}
	else if(m == n){
		ans = a[1];
		for(int i = 1; i <= n; i++) ans &= a[i];
	}
	else if(n <= 20 && m <= n){
		dfs(1);
		ans = dans;
	}
	else{
		ans = a[1];
		for(int i = 2; i <= m; i++) ans &= a[i];
	}
	
	cout << ans;
	return 0;
} 
