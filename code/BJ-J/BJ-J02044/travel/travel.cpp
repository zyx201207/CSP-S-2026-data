#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
bool a = 0, b = 0, d = 0, e = 0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c >> s >> cc >> ss;
    if(c == cc){
        a = 1;
    }
    if(s[0] == ss[0] && s[1] == ss[1]){
        if(a){
            b = 1;
        }
    }
    if((s[2] - 'A' <= 2 && ss[2] - 'A' <= 2) || (s[2] - 'A' > 2 && ss[2] - 'A' > 2)){
        if(b){
            d = 1;
        }
    }
    if(abs(s[2]-ss[2]) == 1){
        if(d){
            e = 1;
        }
    }
    cout << a << b << d << e << endl;
    return 0;
}
