#include<bits/stdc++.h>
using namespace std;
long long int a, b, c = 0, z = 0, s, q = 0, cnt;
char x[2000010], l;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> z;
    if(z==1){
        cout<<0;
        return 0;
    }
    for (int i = 1 ; i <= z; i ++){
        cin >> b >> l;
        for (int j = c; j <= b+c; j++) x[j] = l;
        c += b;
    }
    s = c / 2;
    for (int i = 1; i <= s; i ++){
        //cnt = x[c - i + 1];
        if(x[i] != x[c-i+1]) q+=1;
    }
    cout << q;
    return 0;
}
