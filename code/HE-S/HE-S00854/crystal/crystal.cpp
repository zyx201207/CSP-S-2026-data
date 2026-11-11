#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n,m,a[N],b[N],st[40][N];
inline long long quert(long long l,long long r){
	long long k = log2(l - r + 1);
	return max(st[k][l],st[k][r - (1 << k) + 1]);
}
inline bool check(long long x){
	long long sum = 0,pw;
	for(int i = x;i <= n;i ++){
		sum = quert(i - x + 1,i);
		pw = (sum * x) - (b[i] - b[i - x]);
		if(pw <= m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n,[](long long a,long long b){return a < b;});
	for(int i = 1;i <= n;i ++){
		b[i] = b[i - 1] + a[i];
		st[0][i] = a[i];
	}
	for(int i = 1;(1 << i) <= n;i ++){
		for(int j = 1;j <= n;j ++){
			st[i][j] = max(st[i - 1][j],st[i - 1][j + (1 << (i - 1))]);
//			cout << st[i][j] << " ";
		}
//		cout << "\n";
	}
//	cout << quert(1,4);
	long long l = 0,r = n + 1,mid;
	while(l + 1 != r){
		mid = (l + r) >> 1;
		if(check(mid)){
			l = mid;
		}else{
			r = mid;
		}
	}
	cout << l;
	return 0;
}
