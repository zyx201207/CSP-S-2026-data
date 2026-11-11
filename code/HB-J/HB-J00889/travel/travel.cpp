#include <bits/stdc++.h>
using namespace std;
struct T{
    int c[3];
    string s;
}a;
bool f[5];
int main(){
    freopen("travel.in","r",std.in);
    freopen("travel.out","w",std.out);
    for(int i=1;i<=2;i++) cin >> a.c[i] >> a.s[i];
    if(a.c[1]!=a.c[2]) cout << 0000;
    else {
        f[1]=1;
        if(a.s[1]!=a.s[2]){
            f[2]=0;
            f[3]=0;
        } else {
            f[2]=1;
            if(a.s[1]-a.s[2]>2||a.s[1]-a.s[2]<-2) f[3]=0;
            else f[3]=1;
        }
        if(a.s[1]-a.s[2]==1||a.s[1]-a.s[2]==-1) f[4]=1;
    }for(int i=1;i<=4;i++) cout << f[i];

    return 0;
}
