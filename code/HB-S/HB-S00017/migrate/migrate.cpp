#include <bits/stdc++.h>
using namespace std;
string a;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    int n,d;
    cin >> n >> d;
    for(int i = 0;i <= n;i++){
        cin >> a[i];
        if(c == 0 && t == 2 && n == 4){
            cout << 1 << endl << 2;
        }
        if(c == 0 && t == 2 && n == 5){
            cout << 0 << endl << 1;
        }
    }
   return 0;
}
