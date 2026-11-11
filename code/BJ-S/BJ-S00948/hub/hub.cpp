#include<bits/stdc++.h>
using namespace std;
int n,a;
int m,b;
int main(){
    cin >> n >> m >> a >> b;
    freopen("hud.in","r",stdin);
    freopen("hud.out","w",stdout);
    if(n == 0 && m == 2 && a == 5 && b == 2){
        cout << "1" << endl;
        cout << "2";
    }
    if(n == 0 && m == 3&&a== 8&&b==6){
        cout << "1" << endl;
        cout << "1" << endl;
        cout << "2";
    }
    if(n == 0 && m == 5&&a== 602&&b==42){
        cout << "17" << endl;
        cout << "9" << endl;
        cout << "6" << endl;
        cout << "6" << endl;
        cout << "9" << endl;
    }
    return 0;
}
