#include <bits/stdc++.h>
using namespace std;
template<typename T>inline void rd(T &x){int f=1;char ch;for(;ch<'0'||ch>'9';ch=getchar()){if(ch=='-')f=-1;}x=0;for(;ch>='0'&&ch<='9';ch=getchar()){x=x*10+(ch-'0');}if(f==-1 && !std::is_unsigned<T>::value) x*=f;};
constexpr int N = 2e5+5; int a[N];
bool vis[N];
int ans;
int n, m;
void dfs(int d, int sum){
	
	if(d > m){
		ans = max(ans, sum);
	}
	for(int i = 1; i <= n; i ++){
		if(d == 1) sum = a[i];
		if(!vis[i]){
			vis[i] = 1;
			dfs(d+1,(sum&a[i]));
			vis[i] = 0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	rd(n); rd(m);
	int maxa = 0;
	//cout << n << ' ' << m;
	for(int i = 1; i <= n; i ++){
		rd(a[i]);
		maxa = max({maxa, a[i]});
	}
	if(n == 1){
		cout << maxa;
		return 0;
	}
	
	dfs(1,0);
	
	cout << ans;
	return 0;
}
/*
4 2
3 15 12 12
*/
/*
5 3
31 3 1 15 7
*/
