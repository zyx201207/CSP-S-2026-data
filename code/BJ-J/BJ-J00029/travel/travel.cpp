#include<bits/stdc++.h>
using namespace std;
string a, b, c, d;
bool f[10] = {};
int x, y;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> b >> c >> d;
    for(int i = 0;i <= 1; i++){
        int u = b[i] - '0';
        int v = d[i] - '0';
        x += u;
        y += v;
        x *= 10;
        y *= 10;
    }
    x /= 10;
    y /= 10;
    if(a == c){
        f[0] = 1;
        if(x == y){
            f[1] = 1;
            if(b[2] <= 'C' && b[2] >= 'A' && d[2] <= 'C' && d[2] >= 'A' || b[2] >= 'D' && b[2] <= 'F' && d[2] >= 'D' && d[2] <= 'F'){
                f[2] = 1;
                if(b[2] == d[2] - 1 || d[2] == b[2] - 1){
                    f[3] = 1;
                }
            }
        }
    }
    for(int i = 0;i < 4; i++){
        cout << f[i];
    }
    return 0;
}
