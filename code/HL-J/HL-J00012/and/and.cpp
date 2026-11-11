#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long powr[30];
int a[N], n, m;
vector<int> ver[30];
bool vis[30][N];
void powe(){
	powr[0] = 1;
	for(int i = 1; i < 30; i++){
		powr[i] = powr[i - 1] * 2;
	}
}
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	powe();
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 1; i <= n; i++){
		int j = 29;
		int b = a[i];
		while(b > 0){
			if(b < powr[j]) vis[29 - j][i] = 0;
			else{
				b %= powr[j];
				vis[29 - j][i] = 1;
			}
			j--;
		}
	}
	for(int i = 0; i <= 29; i++){
		int cnt = 0;
		for(int j = 1; j <= n; j++){
			if(cnt == m) {
				int ans = ver[i][0];
				for(int k = 0; k < ver[i].size(); k++){
					ans &= ver[i][k];
				}
				cout << ans;
				return 0;
			}
			if(vis[i][j] == 1) {
				ver[i].push_back(a[j]);
				cnt++;
			}
		}
	}
	cout << 0;
	return 0;
}
		
                                           