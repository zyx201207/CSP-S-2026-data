#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _for(i, x, y) for(int i = (x); i <= (y); ++i)
const int N = 2e5 + 5;
string ax, ay, bx, by;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> ax >> ay >> bx >> by;
    if(ax != bx) cout << 0 << 0 << 0 << 0;
    else{
        cout << 1;
        if(ay[0] != by[0] || ay[1] != by[1]) cout << 0 << 0 << 0;
        else{
            cout << 1;
            char a = ay[2], b = by[2];
            if(('A' <= a && 'C' >= a && 'A' <= b && 'C' >= b) || ('D' <= a && 'E' >= a && 'D' <= b && 'E' >= b)){
                cout << 1;
                if(abs(a - b) == 1) cout << 1;
                else cout << 0;
            }
            else cout << 0 << 0;
        }
    }
     return 0;
}
