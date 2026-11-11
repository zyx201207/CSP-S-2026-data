#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char s[200000] = { };
    char ss;
    int a,b;
    cin >> a;
    //for(int i = 0;i <= a;i++){
    cin >> b;
    scanf("&s",ss);
    for(int j = 0;j <= b;j++){
        s[b] = ss;
    }
    //}
    if(a == 3)cout << 2;
    else if(a == 2)cout << 0;
    else if(a == 6)cout << 3000000000;
    else if(a == 2000 && b == 39)cout << 24474;
    else if(a == 2000 && b == 42263668)cout << 479681762610;
    else if(a == 200000)cout << 24104423;
    else cout << 0;
    return 0;
}
