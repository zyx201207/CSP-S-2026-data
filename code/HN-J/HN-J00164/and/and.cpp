#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pi pair<int,int>
#define mini pi,vector<pi>,greater<pi>
#define p_q priority_queue
#define fs first
#define se second
using namespace std;
const int N = 2e5 + 5;
const int inf = 0x3f3f3f3f3f3f3f3f;

int n, m;
int a[N];
int ans = 0;

void dfs(int d, int cnt, int sad){
	if(d > n + 1) return;
	if(cnt == m){
		ans = max(ans, sad);
		return;
	}
	dfs(d + 1, cnt, sad);
	if(sad == 0) dfs(d + 1, cnt + 1, a[d]);
	else dfs(d + 1, cnt + 1, (sad & a[d]));
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin); freopen("and.out","w",stdout);

	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	dfs(1, 0, 0);
	
	cout << ans;

	return 0;
}

