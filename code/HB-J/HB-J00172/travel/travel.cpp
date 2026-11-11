#include <bits/stdc++.h>
using namespace std;
string ans;

bool f(char a, char b){
    if ((a >= 'A' && b <= 'C') || (a >= 'D' && b <= 'F')){
        return true;
    }
    return false;
}
bool d(char a, char b){
    /*if(a < a){
        char t;
        t = a;
        a = b;
        b = t;
    }*/
    int aa = (int) a;
    int bb = (int) b;
    if(a - b == 1 || b - a == 1){
        return true;
    }
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x,y;
    int a,b;
    int x1 = 0,y1 = 0;
    char x2,y2;
    cin >> a >> x >> b >> y;
    x1 = (int) x[0] * 10 + (int) x[1];
    y1 = (int) y[0] * 10 + (int) y[1];
    x2 = x[2];
    y2 = y[2];
    if(a != b){
        cout << "0000";
    } else{
        if(x1 != y1){
            cout << "1000";
        } else{
            if(!f(x2,y2)){
                cout << "1100";
            } else{
                if(!d(x2,y2)){
                    cout << "1110";
                } else {
                    cout << "1111";
                }
            }
        }
    }
    return 0;
}
