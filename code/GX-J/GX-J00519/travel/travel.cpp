#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f;
string n;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>n>>b;
    c=n[0]-'0'*10+n[1]-'0';
    e=n[2];
    cin>>n;
    d=n[0]-'0'*10+n[1]-'0';
    f=n[2];
    if(a==b && a!=1 && a!=16 && b!=1 && b!=16){
        cout<<1;
        if(c==d){
            cout<<1;
            if(e>='A' && e<='C' && f>='A' && f<='C'){
                cout<<1;
                if(abs(e-f)==1) cout<<1;
                else cout<<0;
            }
            else if((e=='D' && f=='F') || (e=='F' && f=='D')) cout<<11;
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
