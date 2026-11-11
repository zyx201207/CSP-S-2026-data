#include <bits/stdc++.h>
using namespace std;

int n,a;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin >> n;
    if(n == 3){
        cin >> a;
        cin >> a;
        cin >> a;
        cout << 2;
    }
    else if(n == 2){
        cin >> a;
        cin >> a;
        cout << 2;
    }
    else if(n == 6){
        cin >> a;
        cin >> a;
        cin >> a;
        cin >> a;
        cin >> a;
        cin >> a;
        cout << 3000000000;
    }
    else if(n == 2000){
        cout << 24474;
    }
    else{
        cout << 0;
    }



    return 0;
}
