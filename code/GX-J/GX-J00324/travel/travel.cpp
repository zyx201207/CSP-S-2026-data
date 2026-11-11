#include <bits/stdc++.h>
bool tp1,tp2;
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,c;
    string b,d;
    cin>>a>>b>>c>>d;

    if(a==c) {cout << '1';tp1=1;}
    else cout << '0';


    int k,s;k=b[0]+b[1];s=d[0]+d[1];
    if(tp1){
    if(k==s) {cout << '1';tp2=1;}
    else cout << '0';
    }
    else cout << '0';

    string p="ABC",o="DF";
    bool tx=0;
    if(tp1&&tp2){
        if(b[2]=='A'&&(d[2]=='B'||d[2]=='C')) {cout<<'1';tx=1;}
        if(b[2]=='B'&&(d[2]=='A'||d[2]=='C')) {cout<<'1';tx=1;}
        if(b[2]=='C'&&(d[2]=='B'||d[2]=='A')) {cout<<'1';tx=1;}
        if(b[2]=='D'&&d[2]=='F') {cout<<'1';tx=1;}
        if(b[2]=='F'&&d[2]=='D') {cout<<'1';tx=1;}
        if(!tx) cout<<'0';
    }
    else cout << '0';

    if(tp1&&tp2&&tx){
        if(b[2]=='A'&&d[2]=='B') cout<<'1';
        if(b[2]=='B'&&d[2]=='A') cout<<'1';
        if(b[2]=='B'&&d[2]=='C') cout<<'1';
        if(b[2]=='C'&&d[2]=='B') cout<<'1';
        if(b[2]=='D'&&d[2]=='F') cout<<'1';
        if(b[2]=='F'&&d[2]=='D') cout<<'1';
    }
    else cout << '0';
    return 0;
}
