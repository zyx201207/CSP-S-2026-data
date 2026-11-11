#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a>>b>>c>>d;
if(a[1]!=c[1]){
    cout<<0<<0<<0<<0;
    return 0;
}
if(a[1]==c[1]){
    cout<<1;
    if(b[1]==d[1]){
        cout<<1;
    }else{
        cout<<0;
    }
    if(b[1]==d[1]){
        if((b[2]>='A' and b[2]<='c' and d[2]>='A' and d[2]<='C') or (b[2]>='E' and b[2]<='F' and d[2]>='E' and d[2]<='F')){
            cout<<1;
            if(b[2]+1==d[2] or b[2]-1==d[2]){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
        else{
            cout<<0<<0;
        }
    }
    else{
        cout<<0<<0;
    }
}





return 0;
}
