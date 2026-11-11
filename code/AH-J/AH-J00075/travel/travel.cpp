#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c){cout<<"0000";return 0;}
    else if(b[0]!=d[0]||b[1]!=d[1]){cout<<1000;return 0;}
    else if(b[2]>='A'&&b[2]<='C'){
        if(d[2]>='A'&&d[2]<='C'){
            if(b[2]+1==d[2]||b[2]-1==d[2]) cout<<1111;
            else cout<<1110;
        }else{
            cout<<1100;
        }
    }else if(b[2]=='D'||b[2]=='F'){
        if(d[2]=='D'||d[2]=='F'){
            cout<<1111;
        }else{
            cout<<1100;
        }
    }
    return 0;
}
