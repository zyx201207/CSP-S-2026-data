#include<bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MAXN = 500005;
const int MAXM = 300005;

int n, m;
int a[MAXN];
int pos[MAXM];
int ans[MAXN];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	memset(pos, -1, sizeof(pos));

	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(pos[a[i]] != -1){
			for(int j = pos[a[i]] + 1; j <= i - 1; j++)
				ans[a[j]] = max(pos[a[i]], ans[j]);
		}
		pos[a[i]] = i;
	}
	for(int i = 1; i <= m; i++)
		cout << max(pos[i] - ans[i], 0) << " ";
}
