#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a[50010];
long long g[5005][5005];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int cnt = 0, an = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }sort(a, a + n);
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            g[i][j] = a[j] - a[i];
            cout << g[i][j] << " ";
        }cout << endl;
    }for(int i = 1; i < n; i++){
        cnt = 0;
        for(int j = 0; j < n; j++){
            cnt += g[i][j];
        }if(cnt <= m){
            an = max(an, i);
        }
    }cout << an;
    return 0;
}
