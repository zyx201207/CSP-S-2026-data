#include <bits/stdc++.h>
#define int long long
#define f(i,l,r) for(int i = l;i<=r;i++)
#define fe(i,l,r) for(int i = l;i>=r;i--)

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
bool can[N];
int n,m;

signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	f(i,1,n)cin >> v[i];
	
	f(i,1,n)can[i] = 1;
	
	int ans =0;
	fe(j,30,0){
//		f(i,1,n)cout << can[i] << ' ';cout <<endl;
//		f(i,1,n)cout << (((v[i]>>j) & 1) && can[i]) << ' ';cout <<endl;
		
		int cnt = 0;
		f(i,1,n)if(((v[i]>>j) & 1) && can[i])cnt ++ ;
		
//		cout << cnt << endl;
		
		if(cnt < m)continue;
		if(cnt >= m){
			f(i,1,n)if(!((v[i]>>j) & 1))can[i] = 0;
			ans += (1ll << j);
		}
	}
	
	cout <<ans <<endl;
	
	return 0;
}


