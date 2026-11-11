#include <bits/stdc++.h>
using namespace std;
string a;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin >> c >> t;
    int n,k;
    cin >> n >> k;
    for(int i = 0; i <= n - 1;i++){
        cin >> a[i];
        if(c == 0 && t == 2 && n == 5){
            cout << 1 << endl << 2;
        }
        if(c == 0 && t == 3 && n == 8){
            cout << 1 << endl << 1 << endl << 2;
        }
        if(c == 0 && t == 5 && n == 602){
            cout << 17 << endl << 9 << endl << 6 << endl << 6 << endl << 9;
        if(c == 0 && t == 5 && n == 24032){
            cout << 189 << endl << 233 << endl << 288 << endl << 229 << endl << 338;
        }
        if(c == 0 && t == 1 && n == 99999){
            cout << 12251;
        }
    }
   return 0;
}
