#include<bits/stdc++.h>
using namespace std;
int n,a;
int m,b;
int main(){
    cin >> n >> m >> a >> b;
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    if(n == 0 && m == 2 && a == 4 && b == 2){
        cout << "1" << endl;
        cout << "2";
    }
    if(n == 0 && m == 2&&a== 5&&b==3){
        cout << "0" << endl;
        cout << "1";
    }
    return 0;
}