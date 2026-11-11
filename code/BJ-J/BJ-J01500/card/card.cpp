#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
bool flag1 = 1;
int n, m;
int a[N];
int pos[N];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if(a[i] < a[i - 1]) flag1 = 0;
        pos[a[i]]++;
    }
    if(flag1){
		long long k = 0;
		for(int i = 1; i <= m; i++){
			if(pos[i]){
                k += pos[i];
				cout << k << " ";
			}
		}
    }
    return 0;
}
