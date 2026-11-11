#include<bits/stdc++.h>
using namespace std;

int t[300010], a[500010], ans[300010];
int last = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int j = 1; j <= n; j++){
		last = 0;
		for(int i = j; i <= n; i++){
			bool flag = true;
			for(int k = 1; k <= last; k++){
				if(t[k] == a[i]){
					flag = false;
					last = k;
					break;
				}
			}
			if(flag)
				t[++last] = a[i];
		}
		for(int i = 1; i <= last; i++){
			ans[t[i]]++;
		}
		for(int i = 1; i <= m; i++){
			t[i] = 0;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << ' ';
	}

    return 0;
}
