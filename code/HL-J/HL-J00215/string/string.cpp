#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin >> n;
    string a;

    for (int i=1;i<=n;i++){
        long long num;
        char m;
        cin >> num >> m;
        for (int f=0;f<num;f++){
            a = a + m;
        }
        if (i==n){break;}
    }
    string b;
    for (int i = a.size()-1;i>=0;i--){
        b = b+ a[i];
    }
    if(b==a){
        cout << int(a.size()/2);
    }
    else{cout << 0;}
    return 0;

}
