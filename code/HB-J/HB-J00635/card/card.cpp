#include<bits/stdc++.h>
using namespace std;
int a[500010];
long long s[500010];
long long cnt[500010];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    int id = 1;
    for(int i = 1; i <= n; i++){
        s[id] = cnt[i] + s[id - 1];
        id++;
    }
    for(int i = 1; i <= m; i++){
        cout << s[i] << " ";
    }
    return 0;
}
//16
