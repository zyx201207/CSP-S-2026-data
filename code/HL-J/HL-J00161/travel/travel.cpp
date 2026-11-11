#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string c1,s1,c2,s2;
    bool a=0,b=0,c=0,d=0;
    cin >> c1 >> s1 >>c2 >> s2;
    if(c1==c2){
        a=1;
        int pai_a=stoi(s1.substr(0,2)),pai_b=stoi(s2.substr(0,2));
        if(pai_a==pai_b){
            b=1;
            if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
                c=1;
                if(abs(s1[2]-s2[2])==1) d=1;
            }
        }
    }
    cout << a << b << c << d << '\n';
    return 0;
}
