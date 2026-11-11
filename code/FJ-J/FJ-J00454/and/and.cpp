#include<bits/stdc++.h>
using namespace std;
int n, m, ans;
int a[200050];
int twm[35];
bool flag[200050][31];
bool sta[200050][32];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	memset(flag, 0, sizeof(flag));
	int twt = 1;
	for(int i = 0; i < 31; i++){
		twm[i] = twt;
		twt <<= 1;
	}
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 31; j++){
			if(a[i] & twm[j]){
				flag[i][j] = true;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		sta[i][31] = true;
	}
	int stayi = 31;
	for(int i = 30; i >= 0; i--){
		int hn = 0;
		for(int j = 1; j <= n; j++){
			if(!sta[j][stayi]){
				continue;
			}
			if(flag[j][i]){
				sta[j][i] = true;
				hn++;
			}
		}
		if(hn >= m){
			stayi = i;
		}
	}
	int k = 0;
	for(int i = 1; i <= n; i++){
		if(sta[i][stayi]){
			k++;
			if(k == 1){
				ans = a[i];
			}
			else{
				ans = (ans & a[i]);
			}
		}
	}
	cout << ans;
	return 0;
}

