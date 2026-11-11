#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int t[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i){
        cin >>a[i];
        t[a[i]] ++;
    }
    int to = 0;
    for(int i = 1; i <= m; ++i){
        to += t[i];
        cout <<to <<" ";
    }
    return 0;
}
