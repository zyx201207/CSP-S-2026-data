#include<bits/stdc++.h>
using namespace std;
int a,b;
char n[20],m[20];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> n >> b >> m;
    if(a == b){
        cout << 1;
        if(n[1] == m[1] && n[0] == m[0]){
            cout << 1;
            if((65 <= n[2] && n[2] <= 67) && (68 <= m[2] && m[2] <= 69)){
                cout << 0;
                cout << 0;
                return 0;
            }else if((65 <= m[2] && m[2] <= 67) && (68 <= n[2] && n[2] <= 69)){
                cout << 0;
                cout << 0;
                return 0;
            }else{
                cout << 1;
                if(abs(n[2] - m[2]) == 1){
                    cout << 1;
                    return 0;
                }
                cout << 0;
                return 0;
            }
            cout << 0;
            cout << 0;
            return 0;
        }
        cout << 0;
        cout << 0;
        cout << 0;
        return 0;
    }
    cout << 0;
    cout << 0;
    cout << 0;
    cout << 0;
    return 0;
}
