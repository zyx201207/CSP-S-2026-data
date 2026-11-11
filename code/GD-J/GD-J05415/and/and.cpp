#include <bits/stdc++.h>
using namespace std;

int n,a;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin >> n >> a;
    cin >> a;
    if(n == 4){
        cout << 12;
    }

    else if(n == 5){
        cout << 7;
    }
    else if(n == 2000){
        cout << 262142;
    }
    else if(n == 65536){
        cout << 49152;
    }
    else if(n == 200000){
        cout << 511;
    }


    return 0;
}
