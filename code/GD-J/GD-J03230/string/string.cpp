#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define endl '\n'
const int maxn = 2e5 + 5;
int n;
int a[maxn];
char c[maxn]; 
ll res;
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	
	int nowl = 1 , nowr = n , inl = 1 , inr = 1;
	
	for (int i = 1; i <= n; i++){
		if (nowl >= nowr) break;
		int curl = a[nowl] - inl + 1 , curr = a[nowr] - inr + 1;
		if (curl < curr){
			res += (curl * (c[nowl] != c[nowr]));
			inr += curl;
			nowl++;
			inl = 1;
		}else if (curl == curr){
			res += (curl * (c[nowl] != c[nowr]));
			nowl++;
			nowr--;
			inl = 1;
			inr = 1;
		}else{
			res += (curr * (c[nowl] != c[nowr]));
			inl += curr;
			nowr--;
			inr = 1;
		}
	}
	cout << res << endl;
	return;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}

