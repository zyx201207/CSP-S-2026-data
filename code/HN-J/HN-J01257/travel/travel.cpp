#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
//const ll INF = 4e18;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    bool p1=0,p2=0,p3=0,p4=0;
    if (a == c) p1 = 1;
    if (b[0] == d[0] && b[1] == d[1] && p1) p2 = 1;
    if (p2) {
        if (b[2] == 'F' || b[2] == 'D') {
            if (b[2] == 'F' && d[2] == 'D') {
                p3 = 1;
                p4 = 1;
            } else if (b[2] == 'D' && d[2] == 'F') {
                p3 = 1;
                p4 = 1;
            }
        } else {
            if (d[2] == 'A' || d[2] == 'B' ||d[2] == 'C') p3 = 1;
            if (!(d[2] == 'C' && b[2] == 'A' || d[2] == 'A' && b[2] == 'C')
                && !(d[2] == 'D' && b[2] == 'C' || d[2] == 'C' && b[2] == 'D')) {
                p4 = 1;
            }
        }
    }

    cout << p1 << p2 << p3 << p4;


    return 0;
}

