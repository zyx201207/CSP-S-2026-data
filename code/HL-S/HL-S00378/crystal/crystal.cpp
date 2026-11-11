#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500005], ans;
void cry(int k){
    long long b = k, c = 0, d = m;
    while(b >= 0){
        d -= (a[k] - a[b]);
        if(d >= 0){
            c++;
        }
        else
            break;

        b--;
    }
    ans = max(c, ans);
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        printf("%d", a[i]);
    sort(a, a + n);
    for(int i = 0; i < n; i++)
        cry(i);
    scanf("%d\n", ans);
    return 0;
}
