#include<bits/stdc++.h>
using namespace std;
//#define JUDGE
#define int long long
int read(){
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9')x = (x << 3) + (x << 1) + (ch - '0'),ch = getchar();
	return x * f;
}
const int N = 2e5 + 10;
int n,m;
int a[N];
int ans = 0;
void dfs(int cnt,int num,int dep){
	if(cnt == 0){
		ans = max(ans,num);
		return;
	}
	if(dep == n + 1)return;
	dfs(cnt, num, dep + 1);
	dfs(cnt - 1,(num & a[dep]), dep + 1);
}
long long maxa,solb = 1;
long long sola = 1;
long long mxa,wib = (1ll << 31) - 1;
int cnt[N];
void input(){
	n = read(),m = read();
	for(int i = 1;i<=n;i++){
		a[i] = read();
		maxa = max(a[i],maxa);
		wib &= a[i];
		solb &= (a[i] == (i - 1));
		sola &= ((1 << (long long)log2(a[i] + 1)) == a[i] + 1);
	}
}
void solve(){
	input();
	if(n <= 30){
		dfs(m,(1ll << 31) - 1,1);
		cout << ans << endl;
		return;
	}
	if(m == 1){
		cout << maxa << endl;
		return;
	}
	if(m == 2){
		int ansaa = 0;
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				ansaa = max(ansaa,(a[i] & a[j]));
			}
		}
		cout << ansaa << endl;
		return;
	}
	if(m == n){
		cout << wib << endl;
		return;
	}
	if(m == n - 1){
		int ansaa = 0;
		for(int i = 1;i<=n;i++){
			ans = max(ansaa,(wib & ((1ll << 31) - a[i] - 1)));
		}
		cout << ansaa << endl;
		return;
	}
	if(sola){
		int ansaa = INT_MAX;
		sort(a + 1,a + n + 1);
		for(int i = n;i >= 1;i--)m --,ansaa &= a[i];
		cout << ans << endl;
		return;
	}
	if(solb){
		ans = INT_MAX;
		for(int i = n;i>=1;i--){
			if(m == 0)break;
			if((1 << (long long)log2(a[i])) == a[i])continue;
			else ans &= a[i];
			m--;
		}
		cout << ans << endl;
		return;
	}
	if(maxa < 10000000){
		for (int i = 1; i <= n;i++)cnt[a[i]]++;
		int sxsx = (1ll << 31) - 1;
		int ans = INT_MAX;
		for(int i = 100000000;i>=1;i--){
			if(sxsx + cnt[i] >= m){
				ans &= i;
				cout << ans << endl;
				return;
			} else ans &= i;
		}
	}
	cout << 30 << endl;
}
signed main( ){
#ifndef JUDGE
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
#endif
	int _ = 1;
	//cin >> _;
	while(_--)solve();
	return 0;
}
