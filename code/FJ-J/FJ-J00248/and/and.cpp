#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[2001];
int and1(int x,int y){
	int a1,a2,s = 0;
	int i = 1;
	while(x && y){
		a1 = x % 2;
		a2 = y % 2;
		if (a1 && a2) s += i;
		i *= 2,x /= 2,y /= 2;
	}
	return s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	if (n == m){
		int s;
		cin >> s;
		for (int i = 2; i <= n; i++){
			int x;
			cin >> x;
			s = and1(s,x);
		}
		cout << s;
	}
	else if (m == 1){
		int maxn = 0;
		for (int i = 1; i <= n; i++){
			int x;
			cin >> x;
			if (x > maxn) maxn = x;
		}
		cout << maxn;
	}
	else if (m == 2){
		int maxn = 0;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++){
			for (int j = i+1; j <= n; j++){
				int k = and1(a[i],a[j]);
				if (k >= maxn) maxn = k;
			}
		}
		cout << maxn;
	}
	return 0;
}
