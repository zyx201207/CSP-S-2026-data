#include<bits/stdc++.h>
using namespace std;
long long n, lon, cnt, k, lst, ma;
char lsc;
struct M{
	long long t;
	char c;
}a[200005];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    cin >> a[0].t >> a[0].c;
    for(int i = 1; i < n; i++){
    	cin >> lst >> lsc;
		ma = max(lst, ma);
		if(lsc == a[i - 1].c){
			a[i - 1].t += lst;
			i--, n--;
		}else{
			a[i].t = lst;
			a[i].c = lsc;
		}
	}
	if(n * ma < 200000){
		string s;
		for(int i = 0; i < n; i++){
			int t = a[i].t, c = a[i].c;
			for(int i = 0; i < t; i++){
				s += c;
				lon++;
			}
		}
		for(int i = 0; i < lon / 2; i++){
			if(s[i] != s[lon - i - 1]) cnt++;
		}
		cout << cnt;
    	return 0;
	}
	for(int i = 0; i < n / 2; i++){
		long long x = a[i].t, y = a[n - i - 1].t;
		char sx = a[i].c, sy = a[n - i - 1].c;
		if(sx == sy) cnt += max(x, y) - min(x, y);
		else cnt += max(x, y);
	}
	cout << cnt;
    return 0;
}
