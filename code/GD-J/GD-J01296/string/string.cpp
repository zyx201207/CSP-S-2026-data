#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5+5;
ll n, s, x[N], a1[N], b1[N], ans;
string a, b;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x[i] >> c[i];
		s += x[i];
	}
	ll qwq = 0;
	bool p = 1;
	if(s % 2){
		for(int i = 1; i <= n; i++){
			qwq += x[i];
			if(qwq > s / 2 && p){
				x[i]--;
				p=0;
			}
		}
	}
	s/=2;
	ll m = 0, k = 0, j = 0;
	for(int i = 1; i <= n; i++){
		m += x[i];
		if(m <= s){
			a1[++k] = x[i];
			a[k] = c[i];
		}
		else if(m - x[i] >= s){
			b1[++j] = x[i];
			b[j] = c[i];
		}
		else{
			a1[++k] = s - m + x[i];
			b1[++j] = m - s;
			a[k] = c[i];
			b[j] = c[i];
		}
	}
	ll k1 = 0, j1 = 0;
	while(1){
		if(a1[++k1] <= b1[++j1]){
			if(a[k1] != b[j1]) ans+=a1[k1];
			b1[j1] -= a1[k1];
			j1--;
		}
		else{
			if(a[k1] != b[j1]) ans+=b1[j1];
			a1[k1] -= b1[j1];
			k1--;
		}
		if(k1 > k || j1 > j)
			break;
	}
	cout<< ans;
	return 0;
}
