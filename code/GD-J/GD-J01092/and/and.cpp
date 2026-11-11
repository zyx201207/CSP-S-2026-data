#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+7;
int a[N];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n,m, maxx = -1, anss; cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		maxx = max(maxx,a[i]);
		if(i == 1) anss = a[i];
		else anss = (a[i] & anss);
	}
	if(m == 1){
		cout << maxx;
		return 0;
	}
	if(m == n){
		cout << anss;
		return 0;
	}
	anss = -1;
	if(m == 2){
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				anss = max(anss, (a[i] & a[j]));
			}
		}
		cout << anss ;
		return 0;
	}
	anss = -1;
	if(n <= 20){
		int nn = 1;
		for(int i = 1; i <= n; i++) nn *= 2;
		for(int i = 1; i <= nn; i++){
			int xx = i;
			int ans = -1;
			int jj = 1;
			int lenn = 0;
			while(xx){
				if(lenn == m)break;
				if(xx & 1){
					if(ans == -1) ans = a[jj];
					else ans &= a[jj];
					lenn++;
				}
				xx = xx >> 1;
				jj++;
			}
			if(lenn == m) anss = max(anss, ans);
			
		}
		cout << anss;
		return 0;
	}
	
	return 0;
}
