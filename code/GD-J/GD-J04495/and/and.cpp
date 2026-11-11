 #include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int a[N] = {};
int n,m;
int tot = 0;
void dfs(int npos,int ans,int cg) {
	if(npos == n || cg == m) {
		
		if(cg == m){
//			cout << cg << " " << tot  << " " << ans << '\n';
			tot = max(tot,ans);
		}
		
		return ;
	}

	if(cg == 0) dfs(npos+1,a[npos+1],cg+1);
	dfs(npos+1,a[npos+1]&ans,cg+1);

	
	dfs(npos+1,ans,cg);
	return ;
}
int quick_pow(int a,int b) {
	int sum = 1;
	while(b) {
		
		if(b&1) {
			sum *= a;
		}
		
		b >>= 1;
		a = a*a;
	}
	return sum;
} 
signed main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin >> n >> m;
	
	for(int i = 1; i <= n; i ++ ) {
		cin >> a[i];
	}

	if(m == 1)  {
		sort(a+1,a+n+1);
		cout << a[n] << '\n';
	}
	if(m == 2) {
		int ans = 0;
		for(int i = 1; i <= n; i ++ )  {
			for(int j = 1; j <= n;j ++) {
				if(i == j)  {
					continue;
				}
				ans = max(ans,a[i]&a[j]);
			}
		}
		
		cout << ans << '\n';
		return 0;
	}
	
	if(m == n) {
		int ans = a[1];
		for(int i = 2; i <= n;i ++ ) {
			ans &= a[i];
		}
		
		cout << ans << '\n';
		return 0;
	}	
	if(n <= 20) {
		dfs(1,0,0);
		dfs(1,a[1],1);
		
		cout << tot << '\n';
		return 0;
	}
	bool flag = 0;
	
	
	sort(a+1,a+n+1);
	int total = a[n];
	
	for(int i = n; i > n-m;i -- ) {
		total &= a[i];
	}
	
	cout << total << '\n';

	
	
	
	return 0;
}

