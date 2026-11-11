#include<bits/stdc++.h>
#define int long long 

using namespace std;

const int N = 1e6 + 10;
const int M = 1010;
const int mod = 998244353;
const double eps = 1e-9;
typedef long long LL;
typedef unsigned long long ULL;
typedef double db;
typedef pair<int, int> PII;

int n, d;
int a[N];
bool st[N];

void dfs(int u, int s, int t, int &x, set<int> &S){
	if(S.size() > 1) return x = 0, void(0);
	if(u > t){
		int cnt = 0;
		int lst = a[s - 1];
		for(int i = s ; i <= t ; i ++){
			if(st[i]){
				if(abs(a[i] - lst) > d) return ; 
				lst = a[i];
				cnt ++;
			}
		}
		if(abs(a[t + 1] - lst) > d) return ;
		x ++;
		S.insert(cnt);
		if(S.size() > 1) return x = 0, void(0);
		return ;
	}
	
	st[s] = 1;
	dfs(u + 1, s, t, x, S);
	st[s] = 0;
	dfs(u + 1, s, t, x, S);
}

signed main(){
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int _, T;
	cin>>_>>T;
	
	while(T --){
		cin>>n>>d;
		
		for(int i = 1 ; i <= n ; i ++){
			cin>>a[i];	
		}
		
		sort(a + 1, a + n + 1);
		
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++){
			for(int j = i + 1 ; j <= n ; j ++){
				int tmp = 0;
				set<int> S;
				dfs(i + 1, i + 1, j - 1, tmp, S); 
				ans += (tmp == 2);
//				cout<<i<<' '<<j<<' '<<tmp<<'\n';
			}
		}
		cout<<ans<<'\n';
	} 
	
//	cerr<<"Memory : "<<abs(&END - &START) / 1024.0 / 1024.0<<'\n';
	return 0;
}
