#include <bits/stdc++.h>
using namespace std;

//constants
const int N = 2e5 + 7;

//typedefs
typedef long long ll;

//vars
ll n;

ll a[N];
char c[N];

//main
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0),ios::sync_with_stdio(0);
	
	cin >> n;
	
	for(int i = 0; i < n; ++i){
		cin >> a[i] >> c[i];
	}
	
	ll i = 0, j = n - 1;
	char ci = c[i], cj = c[j];
	ll ai = a[i], aj = a[j];
	ll ans = 0;
	while(i <= j){
		if(ci != cj){
			if(ai > aj){
				ai -= aj;
				ans += aj;
				cj = c[--j];
				aj = a[j];
			}
			else{
				aj -= ai;
				ans += ai;
				ci = c[++i];
				ai = a[i];
			}
		}
		else{
			if(ai > aj){
				ai -= aj;
				cj = c[--j];
				aj = a[j];
			}
			else{
				aj -= ai;
				ci = c[++i];
				ai = a[i];
			}
		}
	}
	
	cout << ans << endl;
	return 0;
}
