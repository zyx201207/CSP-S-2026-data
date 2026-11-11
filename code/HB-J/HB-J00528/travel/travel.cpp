#include<bits/stdc++.h>
using namespace std;
int a, b, x, y;
char n, m;
bool flag = 1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> x >> n >> b >> y >> m;
    if(flag && a == b)cout << 1;
    else {
        cout << 0;
        flag = 0;
    }
    if(flag && x == y)cout << 1;
    else {
        cout << 0;
        flag = 0;
    }
    if(flag &&((n <= 'C' && m <= 'C')||(n > 'C' && m > 'C')))cout << 1;
    else {
        cout << 0;
        flag = 0;
    }
    if(flag &&(n == m + 1 || m == n + 1 || n == 'D' || m == 'D'))cout << 1;
    else cout << 0;
    return 0;
}
