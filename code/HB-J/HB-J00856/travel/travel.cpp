#include<bits/stdc++.h>
using namespace std;
int a, b, c, d;
char e, f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> e >> c >> d >> f;
    bool aa = false;
    if(a == c){
        cout << 1;
        aa = true;
    }else{
        cout << 0;
    }
    if(aa == true&&b == d){
        cout << 1;
    }else{
        cout << 0;
        aa = false;
    }
    if(aa == true&&((e >= 'D'&&f >= 'D')||(e <= 'C'&&f <= 'C'))){
        cout << 1;
    }else{
        cout << 0;
    }
    if((e+1 == f&&e+1 != 'D'||e-1 == f&&e-1 != 'C')&& aa == true){
        cout << 1;
    }else{
        cout << 0;
    }
    return 0;
}
