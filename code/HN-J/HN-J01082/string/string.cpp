#include <bits/stdc++.h>
#define int long long
#define f(i,l,r) for(int i = l;i<=r;i++)

using namespace std;

const int N = 1e6 + 5;

int read() {
	int sum = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		sum = sum * 10 + ch - 48;
		ch = getchar();
	}
	return sum * f;
}

int v[N];
char f[N];
int n ;

signed main() {
//	freopen("string6.in","r",stdin);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n ;
	f(i,1,n)cin >> v[i] >> f[i];
//	n = read();
//	f(i,1,n)
	
	int L = 1,R = n;
	int ans = 0;
	while(L < R){
//		cout << L << ' ' << R <<endl;
		int Kei = min(v[L],v[R]);
		if(f[L] != f[R]){
			ans += Kei;
		} 
		v[L] -= Kei;
		v[R] -= Kei;
		if(!v[L])L++;
		if(!v[R])R--;
	}
	
	cout << ans << endl;
	return 0;
}

