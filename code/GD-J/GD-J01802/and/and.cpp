#include<bits/stdc++.h> 
using namespace std;

const int MAXN = 200005;

int n, m;
int a[MAXN];
bool use[2][MAXN];
int now = 0;
int cnt[30];
bool ans_bit[30];
int ans = 0;


int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	memset(use, 1, sizeof(use));
	for(int i = 29; i >= 0; i--){
		for(int j = 1; j <= n; j++){
			if(!use[now][j]){
				use[1 - now][j] = false;
				continue;
			}
			if(((a[j] >> i) & 1) == 1) cnt[i]++, use[1 - now][j] = true;
			else use[1 - now][j] = false;
		}
		if(cnt[i] >= m) ans_bit[i] = 1, now = 1 - now;
		else ans_bit[i] = 0;
	}
	
	for(int i = 0, num = 1; i < 30; i++, num = (num << 1)){
		if(ans_bit[i]) ans += num;
	}
	cout << ans;
}
