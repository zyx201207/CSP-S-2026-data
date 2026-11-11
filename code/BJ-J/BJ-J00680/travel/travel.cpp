#include<bits/stdc++.h>
using namespace std;
int read(){
    char c,s;
    cin>>c>>s;
    return (c-48)*10+s-48;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    char s,t;
    a=read();
    b=read();
    cin>>s;
    c=read();
    d=read();
    cin>>t;
    if(a==c){
        cout<<"1";
        if(b==d){
            cout<<"1";
            if(s<='C' && t<='C' || s>='D' && t>='D'){
                cout<<"1";
                if(abs(s-t)==1 && s<='C' && t<='C' || s=='D' && t=='F' || s=='F' && t=='D'){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}