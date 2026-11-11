#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int s = 0,w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') w = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){s = (s << 3) + (s << 1) + ch - '0';ch = getchar();}
	return s * w;
}
const int MAXN = 2e6 + 8;
int n,d,X[MAXN];
void solve(){
	n = read();d = read();
	int cha = 0;
	for(int i = 1;i <= n;i++){
		X[i] = read();
	}
	cha = X[2] - X[1];
	for(int i = 3;i <= n;i++) if(X[i] - X[i - 1] != cha){cha = -1;break;}
	if(cha != -1){
		if(d <= cha){cout << "0\n";return;}
		int jump = d / cha;
		cout << max(0LL,n - 2 * jump + 1) << "\n"; 
		return;
	}
	else cout << "0\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;C = read();T = read();
	while(T--)
		solve();
	return 0;
}

