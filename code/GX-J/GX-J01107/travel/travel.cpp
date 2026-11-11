#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int x,y,s,t;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    x=(int(a[0])-48)*10+int(a[1])-48;
    y=(int(c[0])-48)*10+int(c[1])-48;
    s=(int(b[0])-48)*10+int(b[1])-48;
    t=(int(d[0])-48)*10+int(d[1])-48;
    if(x==y){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(s==t){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if(b[2]<='C'&&d[2]<='C'){
        cout<<1;
        if(b[2]=='B'||d[2]=='B'){
            cout<<1;
        }else{
            cout<<0;
        }
    }else if(b[2]>'C'&&d[2]>'C'){
        cout<<11;
    }else{
        cout<<"00";
    }
    return 0;
}
