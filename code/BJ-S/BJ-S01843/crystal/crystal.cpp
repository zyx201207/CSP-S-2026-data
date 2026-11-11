#include<bits/stdc++.h>
using namespace std;
int a[100000], b[10000][10000];
int main(){
    int n, m, q,ans = 0,maxn = 0;
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    sort(a, a+n);
    for(int i = 2; i < maxn; i++){
        for(int j = 0; j < n; j++){
            b[i][j] = abs(i - a[j]);
        }
        sort(b[i],b[i]+n);
    }
    for(int i = 2; i < maxn; i++){
        q = m;
        int j = 0;
        int test = 0;
        while(q - b[i][j] > 0){
            if(i == j){
                j++;
                test++;
                continue;
            }
            q -= b[i][j];
            test++;
            j++;
        }
        ans = max(ans, test);
    }
    cout << ans;
    return 0;
}
