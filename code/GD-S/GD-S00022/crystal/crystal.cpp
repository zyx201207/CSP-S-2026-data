#include <bits/stdc++.h>
#define int long long
#define gc getchar
using namespace std;

int Miku(){
	int k = 0,f = 1,c = gc();
	for (;!isdigit(c);c = gc()) if (c == '-') f = -1;
	for (;isdigit(c);c = gc()) k = k * 10 + (c ^ 48);
	return k * f;
}

const int N = 5e5+5;
int n,m,a[N],cnt,c;

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n = Miku(); m = Miku();
	for (int i = 1;i <= n;i++){
		a[i] = Miku();
		if (a[i] == i) cnt++;
		if (i > 2 && a[i] - a[i-1] == a[i-1] - a[i-2]) c++;
	}
	if (cnt == n){
		int sum = 0,i;
		for (i = 1;sum + i <= m;i++){
			sum += i;
			if (i > n) break;
		}
		cout << (i > n ? n : i) << endl;
		return 0;
	}
	if (c == n-2){
		int k = a[2] - a[1],i;
		for (i = 0;i <= n;i++){
			int x = i+1;
			if (k * ((1 + x) * x / 2) > m) break;
		}
		cout << (i+1 > n ? n : i+1) << endl;
		return 0;
	}
	sort(a+1,a+n+1);
	int maxn = -1,x;
	for (int i = 2;i <= n;i++){
		x = m;
		cnt = 1;
		for (int j = i-1;j >= 1;j--){
			if (x - (a[i] - a[j]) >= 0){
				x -= a[i] - a[j];
				cnt++;
			}else break;
		}
		maxn = max(cnt,maxn);
	}
	cout << maxn << endl;
	
	return 0;
}
