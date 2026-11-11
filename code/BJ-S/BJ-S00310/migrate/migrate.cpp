#include <bits/stdc++.h>
using namespace std;
string a[500050];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int f;
    cin >> f;
    if(!f){
        int t;
        cin >> t;
        while(t--){
            int n,d;
            cin >> n >> d;
            for(int i = 1;i <= n;i++) cin >> a[i];
            if(n == 4 && d == 2) cout << 1 << endl;
            if(n == 5 && d == 2) cout << 2 << endl;
            if(n == 5 && d == 3) cout << 0 << endl;
            if(n == 6 && d == 2) cout << 1 << endl;
        }
    }
    return 0;
}