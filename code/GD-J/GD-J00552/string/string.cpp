#include<bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 200000 + 7;
long long len = 0, ans = 0;
char v[MAXN];
int w[MAXN]; 
string s;

int main(){
	
	freopen("string.in", "r", stdin);
	freopen("string.ans", "w", stdout);
	

	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> w[i] >> v[i];
		len += w[i];
	} 
	// ¼ÆÊý 
	if(len % 2 == 1)len++;
	int l = 1, r = n;
	for(int cur = 1; cur <= len / 2 && l <= r; cur++){
		if(v[l] != v[r]){
			ans += min(w[l], w[r]);
			
		}
		int sum = min(w[l], w[r]);
		w[l] -= sum;
		w[r] -= sum;
		if(w[l] == 0)l++;
		if(w[r] == 0)r--;
	}
	cout << ans;
	return 0;
}
