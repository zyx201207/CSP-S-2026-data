#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5+10;
ll n, m;
ll a[MAXN], c[MAXN], b[MAXN];
int ans = 1;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
//	for(int i = 1; i <= n; i++) cout << a[i] <<' ';
	for(int i = 1; i <= n-1; i++){
		c[i] = a[i+1]-a[i];
//		cout << c[i] <<' ';
	}
	for(int i = 1; i <= n-1; i++){
		b[i] = b[i-1] + c[i];
	}

	if(m==0){
		int cnt = 1;
		for(int i = 2; i <= n; i++){
			if(a[i-1] == a[i]){
				cnt++;
			}
			else{
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);
	}
	else{
		ll tmp;
		int p;
		for(int l = 1; l <= n-1; l++){
			if(ans != 1){
				if(l+ans-1 <= n) tmp = tmp - (b[l+ans-3]-b[l-1]) + c[l+ans-2]*(ans-1);
				else break;
				if(tmp > m) continue;
			}
			else tmp = 0;
			p = ans;
			for(int r = l+ans-1; r <= n-1; r++){
				if(tmp <= m - p*c[r]){
//					cout << p << ' ' << c[r] << ' ' << tmp << ' ';
					tmp += p*c[r];
					p++;
				}
				else break;
			}
			
			ans = max(ans, p);

		}
	}
	printf("%d", ans);
	return 0;
	 
}
