#include<bits/stdc++.h>
using namespace std;

struct p{
    int c;
    string s;
};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    p r,x;
    cin >> r.c >> r.s;
    cin >> x.c >> x.s;
    int c1=r.c,c2=x.c;
    string s1=r.s,s2=x.s;
    if(c1==c2){
        cout << 1;
    }
    else cout <<0;
    if(c1==c2&&s1[1]==s2[1]){
        cout << 1;
    }
    else cout << 0;
    if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C'){
        cout << 1;
    }
    else cout << 0;
    if(abs(s1[2]-s2[2])==1)cout << 1;
    else cout << 0;
    return 0;
}
