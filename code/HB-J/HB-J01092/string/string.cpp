#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin >> n;
    string s;
    int a[10005];
    string c[10005];
    int len = 0;
    for(int i = 1;i<=n;i++){
        cin >> a[i] >> c[i];
        for(int j = 1;j <= a[i];j++){
            s = c[i];
            s += "0";
            len++;
        }
    }

    if(n == 1){cout << "0";}
    if(n == 2){
        if(c[1] == c[2]){cout <<"0";}
        else{
            if(a[1] < a[2]){cout << a[1];}
            else{cout << a[2];}
        }

    }
    if(n <= 10){
        for(int i = 1;i < n;i++){
            if(c[i] == c[i+1]){cout << "0";}
            if()
        }
    }

    return 0;
}
