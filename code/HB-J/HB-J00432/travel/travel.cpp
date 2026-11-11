#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
void solve(){
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<0<<0<<0<<0;
        return;
    }else{
        if(b[0]!=d[0] || b[1]!=d[1]){
            cout<<1000;
            return;
        }else{
            if((b[2]>='A' && b[2]>='C' && d[2]>='D' && d[2]<='F') || (b[2]>='D' && b[2]>='F' && d[2]>='A' && d[2]<='C')){
                cout<<1100;
                return;
            }else{
                if((b[2]=='A' && d[2]!='B') || (b[2]=='C' && d[2]!='B') || (b[2]=='B' && (d[2]!='A' || d[2]!='c')) || (b[2]=='D' && d[2]!='F') ||  (b[2]=='F' && d[2]!='D')){
                    cout<<1110;
                    return;
                }
            }
        }
    }
    cout<<1111;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    solve();
    return 0;
}
