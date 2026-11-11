#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    long long a, c;
    string b, d;
    cin >> a >> b >> c >> d;
    while(a != 01 && a != 16 && c != 01 && c != 16 && a <= 17 && c <= 17){
        if(a == c){
            cout << 1000;
        }
        break;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
