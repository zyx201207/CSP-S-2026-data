#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 5;
int c, t, n, d;
ll x[N], ans;
int ss(int i, int j){
	int l = i, r = j; 
	while(l < r){
		int mid = (l + r + 1)/2;
		if(x[mid] <= x[i] + d){
			l = mid;
		}else{
			r = mid - 1;
		}
	}
	int s = 1;
	while(l < j){
		int Ll = l, rr = j; 
		while(Ll < rr){
			int mid = (Ll + rr + 1)/2;
			if(x[mid] <= x[l] + d){
				Ll = mid;
			}else{
				rr = mid - 1;
			}
		}
		l = Ll;
		s++;
	}
	return s;
}
bool check(int xx, int y, int s){
	int l = xx, answ = 1, sum = 0;
	while(l < y){
		int Ll = l, rr = y; 
		while(Ll < rr){
			int mid = (Ll + rr + 1)/2;
			if(x[mid] <= x[l] + d){
				Ll = mid;
			}else{
				rr = mid - 1;
			}
		}
		sum++;
		for(int i = l + 1; i < Ll; i++){
			if(ss(i, y) == s - sum)answ++;
		}
		if(answ > 2)return 0;
		l = Ll;
	}
	if(answ == 2)return 1;
	return 0;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d", &c, &t);
	while(t--){
		scanf("%d%d", &n, &d);
		ans = 0;
		bool flag = 1;
		for(int i = 1; i <= n; i++){
			scanf("%lld", &x[i]);
			if(flag && i > 1 && x[i] - x[i - 1] <= d)flag = 0;
		}
		if(flag){
			printf("0\n");
		}
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				int l = i, r = j; 
				while(l < r){
					int mid = (l + r + 1)/2;
					if(x[mid] <= x[i] + d){
						l = mid;
					}else{
						r = mid - 1;
					}
				}
				if(l == i){
					continue;
				}
				int s = 1;
				while(l < j){
					int Ll = l, rr = j; 
					while(Ll < rr){
						int mid = (Ll + rr + 1)/2;
						if(x[mid] <= x[l] + d){
							Ll = mid;
						}else{
							rr = mid - 1;
						}
					}
					if(Ll == l){
						s = 0;
						break;
					}
					l = Ll;
					s++;
				}
				if(s && check(i, j, s)){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

