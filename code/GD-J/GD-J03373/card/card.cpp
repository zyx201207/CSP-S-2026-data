#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500005];
int jmp[500005];
int ans[300005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	memset(jmp, -0x3f, sizeof jmp);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		jmp[a[i]] = i;
	}
	for(int i = 1;i <= n;i++){
		//game
		for(int j = i;j <= n;j++){
			if(jmp[a[j]] < j) ans[a[j]]++;
			else{
				ans[a[j]]++, j = jmp[a[j]];
			} 
		}
	}
	for(int i = 1;i <= m;i++) cout << ans[i] << ' ';
	return 0;
}

