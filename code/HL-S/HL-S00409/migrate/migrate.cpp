#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 10;
int m, n, c, T;
ll d, a[N];
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> T;
    while(T--){
        cin >> n >> d;
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
