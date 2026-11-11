#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string r,x;
    cin >> a >> r >> b >> x;
    char c = r[2],d=x[2];
    if(a == b){
        cout << 1;
        if(r[0] == x[0] && r[1] == x[1]){
            cout << 1;
            if(c+d != 'C'+'D' && c+d != 'D'+'C'){
                cout << 1;
            }else{
                cout << 0;
            }
            if(abs((int)r[2] - (int)x[2]) == 1 && c+d != 'C'+'D' && c+d != 'D'+'C'){
                cout << 1;
            }else{
                cout <<0;
            }
        }else{
            cout << 0 << 0 << 0;
        }
    }
    else{
        cout << 0 << 0 << 0 << 0;
    }
    return 0;
}
