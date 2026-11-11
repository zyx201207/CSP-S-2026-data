#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;

int n;
ll len, ans;

ll cnt[N];
char c[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> cnt[i];
		len += cnt[i];
		cin >> c[i];
	}
	
	ll idx = 0;
	ll t = len / 2 + len % 2;
	
	for(int i = 1; i <= n; i++){
		if(t < cnt[i]) {
			idx = i;
			break;
		}
		t -= cnt[i];
	} 
	
	ll j = n, i = 1;
	ll cntl = cnt[1], cntr = cnt[n];
	if(idx == 1){
		cntl = t;
	}
	if(idx == n){
		cntl = cnt[n] - t;
	}
	while(i < j){
		if(c[i] != c[j]){
			ll cost = min(cntl, cntr);
			ans += cost;
			cntl -= cost;
			cntr -= cost;
			if(cntl == 0){
				i++;
				cntl = cnt[i];
				if(i == idx){
					cntl = t;
				}
			}
			if(cntr == 0){
				j--;
				cntr = cnt[j];
				if(j ==idx){
					cntr = cnt[j] - t;
				}
			}
		}
		else{
			ll cost = min(cntl, cntr);
			cntl -= cost;
			cntr -= cost;
			if(cntl == 0){
				i++;
				cntl = cnt[i];
				if(i == idx){
					cntl = t;
				}
			}
			if(cntr == 0){
				j--;
				cntr = cnt[j];
				if(j == idx){
					cntr = cnt[j] - t;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
