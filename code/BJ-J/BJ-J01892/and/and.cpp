#include <bits/stdc++.h>
using namespace std;
long long n, b[20005], m;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
		cin >> b[i];
	}
	if(m == 2){
		int maxn = -1;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if((b[i] and b[j]) > maxn){
					maxn = (b[i] and b[j]);
				}
			}
		}
		cout << maxn;
	}
	if(m == 1){
		sort(b+1, b+n+1);
		cout << b[n];
	}
    return 0;
}

