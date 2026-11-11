#include <bits/stdc++.h>
using namespace std;
struct u{
    int cw;//car
    string sw;//sit
}a,b;
bool f=true;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a.cw>>a.sw>>b.cw>>b.sw;
    if(a.cw==b.cw) cout<<1;//1
    else {
        f=false;
        cout<<0;
    }
    if(f==true&&a.sw[0]==b.sw[0]&&a.sw[1]==b.sw[1]) cout<<1;//2
    else {
        f=false;
        cout<<0;
    }
    if(int(a.sw[2])>int('C')){//3
        if(f==true&&int(b.sw[2])>int('C')) cout<<1;
        else {
            f=false;
            cout<<0;
        }
    }else{
        if(f==true&&int(b.sw[2])<int('D')) cout<<1;
        else {
            f=false;
            cout<<0;
        }
    }
    if(f==true&&(int(a.sw[2]+1)==b.sw[2]||int(a.sw[2]-1)==b.sw[2])) cout<<1;//4
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
