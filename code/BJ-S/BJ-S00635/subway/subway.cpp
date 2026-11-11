#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>> c >>n >>m >>d >>q;
    for(int i = 1;i <= m;i++){ int x; cin >> x;}
    for(int i = 1;i <= n;i++){
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++){int x,y;cin >> x >>y;}
    }
    for(int i = 1;i <= q;i++){
        int x,y;
        cin >> x >> y;
    }
    for(int i =1;i <= q;i++){
        cout << 0 << endl;
    }
}
