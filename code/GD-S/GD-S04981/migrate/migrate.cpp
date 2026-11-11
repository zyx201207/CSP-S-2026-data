#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int c, t;

void sol(){
	ll n, d; cin>>n>>d;
	vector<ll> a(n + 5);
	vector<int> nxt(n + 5), pre(n + 5);// 下一个，上一个极限 
	vector<ll> f1(n + 5, 0), f2(n + 5);// 没被污染过，被污染过一次 
	for(int i = 1;i <= n;i++) cin>>a[i];
//	sort(a.begin() + 1, a.begin() + n + 1);
//	a[0] = LLONG_MIN, a[n+1] = LLONG_MAX;
	int r = 1;
	for(int i = 1;i <= n;i++){
		while(a[i] + d >= a[r+1] && r + 1 <= n) r++;
		nxt[i] = r;
	}
	nxt[n] = n + 1;
	int l = n;
	for(int i = n; i; i--){
		while(a[i] - d <= a[l-1] && l-1 >= 1) l--;
		pre[i] = l;
	}
	pre[1] = 0;
//	for(int i = 1;i <= n;i++) cout<<pre[i]<<" \n"[i == n];
//	for(int i = 1;i <= n;i++) cout<<nxt[i]<<" \n"[i == n];
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < i;j++){
			if(nxt[j] == i) f1[i]++;
			if(nxt[j] == i && pre[i] == j) f1[i] += f1[j], f2[i] += f2[j];
			if(pre[i] + 1 == nxt[j] && nxt[nxt[j]] == i && pre[pre[i]] == j && pre[i] != j && pre[nxt[j]] == j && nxt[pre[i]] == i)
				f2[i] += f1[j];
		}
	}
//	for(int i = 1;i <= n;i++) cout<<f1[i]<<" \n"[i == n];
//	for(int i = 1;i <= n;i++) cout<<f2[i]<<" \n"[i == n];
	
	ll res = 0;
	for(int i = 1;i <= n;i++) res += f2[i];
//	cout<<res<<"\n";
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			if(pre[j] + 1 == nxt[i] && pre[j] != i){ // 非严格结 
				res++;
				if(nxt[pre[j]] != j) res += f1[i];
//				cout<<res<<" aalshdflkajshf\n";
//				cout<<i<<" "<<j<<'\n';
			}
		}
	}
	cout<<res<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>t;
	while(t--) sol();
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/

