#include <bits/stdc++.h>
using namespace std;

int n, k, m;
int a[1000010], b[10000010];

int main(){

    freopen("and.in", "r", stdin);
    freopen("and.out", " w", stdout);
    cin >> n >> k;
    for(int i = 1;i <= n; i++){
        cin >> a[i];
        b[a[i]]++;
        m =max(a[i],m);
    }
    if(m == 1){
		cout << m;
		return 0;
	}
	
    for(int i = m; i >= n; i--){
        if(b[i] == 2){
            cout << i;
            return 0;
        }
    }
    cout << m;
    return 0;
}
