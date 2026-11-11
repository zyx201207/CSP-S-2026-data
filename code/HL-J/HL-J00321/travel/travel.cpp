#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int A,B,C,D;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b>>c>>d;
    if(a == c) {
        A = 1;
        string x,y;
        for(int i = 0;i<=1;i++) {
            x+=b[i];
            y+=d[i];
        }
        if(x == y) {
            B = 1;
            int xx,yy;
            if(b[2] == 'A'||b[2] == 'B'||b[2] == 'C') {
                xx = 1;
            }else {
                xx = 0;
            }
            if(d[2] == 'A'||d[2] == 'B'||d[2] == 'C') {
                yy = 1;
            }else {
                yy = 0;
            }
            if(xx == yy) {
                C = 1;
                if((b[2] == 'A'&&d[2] == 'C')||(b[2] == 'C'&&d[2] == 'A')) {
                    D = 0;
                }else {
                    D = 1;
                }
            }
        }
    }
    cout<<A<<B<<C<<D;
    return 0;
}

