#include <bits/stdc++.h>
using namespace std;
#define int long long
bool chk(char a,char b){
    if(a=='B'&&b=='C'||a=='A'&&b=='B'||a=='C'&&b=='B'||a=='B'&&b=='A'||a=='F'&&b=='D'||a=='F'&&b=='D')return true;
    else return false;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    string b1=b.substr(0,2),d1=d.substr(0,2);
    char b2=b[2],d2=d[2];
    cout<<'\n';
    if(a!=c){
        cout<<"0000";
        return 0;
    }

    if(b1!=d1){
        cout<<"1000";
        return 0;
    }
    if(!((b2>='A'&&b2<='C')&&(d2>='A'&&d2<='C'))||!(b2=='F'||b2=='D'&&d2=='F'&&d2=='D')){
        cout<<1100;
        return 0;
    }
    if(((b2>='A'&&b2<='C')&&(d2>='A'&&d2<='C'))||(b2=='F'||b2=='D'&&d2=='F'||d2=='D')&&!chk(b2,d2)){
        cout<<1110;
        return 0;
    }else {
        cout<<1111;
        return 0;
    }
    return 0;
}
