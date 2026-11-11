#include<iostream>
#include<cstring>
#include<algorithm>
#define memset(dest, val, n) __builtin_memet(dest, val, n)
#define fillinf(dest) memset((dest), 0x3f, sizeof(dest))
#define fillninf(dest) memset((dest), 0xc0, sizeof(dest))
#define fillzero(dest) memset((dest), 0, sizeof(dest))
#define fropen(x) freopen(x".in", "r", stdin);freopen(x".out", "w", stdout)
#define closeios() ios::sync_with_stdio(false);cin.tie(0)
template<typename... Args>
void errorf(const char* format, Args... arg){fprintf(stderr, format, arg...);}
#define int2ll 0
#if int2ll
#define int long long
#define intEx signed
#else
#define ll long long
#define intEx int
#endif
using namespace std;

const int maxn=214514;
int n, m;
int a[maxn], b[maxn], ans;
bool spec=true;

void dfs(int d, int cnt){
	if(d==n+1||cnt==m){
		if(cnt<m) return;
		int ret=-1;
		for(int i=1;i<=n;i++){
			if(ret==-1&&b[i]){
				ret = a[i];
			}
			else if(b[i]){
				ret &= a[i];
			}
		}
		ans = max(ans, ret);
		return;
	}
	dfs(d+1, cnt);
	b[d] = 1;
	dfs(d+1, cnt+1);
	b[d] = 0;
}

intEx main(){
	fropen("and");
	closeios();
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(spec){
			bool flag=true;
			for(int i=0;i<=29;i++){
				if(a[i]==(1<<i)){
					flag = 0;
					break;
				}
			}
			if(flag){
				spec = false;
			}
		}
	}
	if(spec){
		sort(a+1, a+n+1);
		cout << a[n-m+1];
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			ans = max(ans, a[i]);
		}
		cout << ans;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans = max(ans, (a[i]&a[j]));
			}
		}
		cout << ans;
	}
	else if(m==n){
		ans = a[1];
		for(int i=2;i<=n;i++){
			ans &= a[i];
		}
		cout << ans;
	}
	else if(m==n-1){
		for(int i=n-1;i>=1;i--){
			b[i] = (b[i+1]&a[i]);
		}
		for(int i=2;i<=n;i++){
			a[i] &= a[i-1];
		}
		ans = max(ans, b[2]);
		ans = max(ans, a[n-1]);
		for(int i=2;i<=n-1;i++){
			ans = max(ans, (a[i-1]&b[i+1]));
		}
		cout << ans;
	}
	else{
		dfs(1, 0);
		cout << ans;
	}
	return 0;
}