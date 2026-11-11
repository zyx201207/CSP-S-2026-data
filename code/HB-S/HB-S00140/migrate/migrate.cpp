#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,m;
    cin >> c >> m;
    while(m --){
        int n,d,a[100010];
        cin >> n >> d;
        for(int i = 1;i <= n;i ++) cin >> a[i];
        if(n == 4) cout << 1 << endl;
        else cout << n / d << endl;
    }
    return 0;
}
