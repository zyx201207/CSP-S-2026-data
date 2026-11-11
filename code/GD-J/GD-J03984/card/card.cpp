#include<iostream>
#include<cstring>
#include<stack>
#define ep emplace
#define memset(dest, val, n) __builtin_memset(dest, val, n)
#define fillinf(dest) memset((dest), 0x3f, sizeof(dest));
#define fillninf(dest) memset((dest), 0xc0, sizeof(dest));
#define fillzero(dest) memset((dest), 0, sizeof(dest));
#define fropen(x) freopen(x".in", "r", stdin);freopen(x".out", "w", stdout);
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

const int maxn=514514;
int n, m, a[maxn], ans[maxn];
bool cnt[maxn];
stack<int> stk;
bool spec=true;

void solve(int l){
	while(!stk.empty()) stk.pop();
	fillzero(cnt);
	for(int i=l;i<=n;++i){
		if(cnt[a[i]]){
			while(!stk.empty()&&stk.top()!=a[i]){
				cnt[stk.top()] = false;
				stk.pop();
			}
		}
		else{
			stk.ep(a[i]);
			cnt[a[i]] = true;
		}
	}
}

intEx main(){
	fropen("card");
	closeios();
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		if(i>1&&a[i]<a[i-1]){
			spec = false;
		}
	}
	if(spec){ // A
		for(int i=1;i<=n;++i) ans[a[i]] = i;
		for(int i=1;i<=m;++i) cout << ans[i] << " ";
		return 0;
	}
	for(int i=1;i<=n;++i){
		solve(i);
		for(int j=1;j<=m;++j) if(cnt[j]) ans[j]++;
	}
	for(int i=1;i<=m;++i){
		cout << ans[i] << " ";
	}
	return 0;
}