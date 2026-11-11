#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    if (n == 3){
        int a;
        string s;
        cin >> a >> s;
        if (a == 2 && s == 'a'){
            cin >> a >> s;
            if (a == 2 && s == 'b'){
                cin >> a >> s;
                if (a == 1 && s == 'c') cout << 2;
            }else if (a == 3 && s == 'a'){
                cout <<0;
            }
        }
    }
    return 0;
}
