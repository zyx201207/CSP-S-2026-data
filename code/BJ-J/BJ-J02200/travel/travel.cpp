#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c)cout<<1;
    else cout<<0;
    string t1,t2;
    t1+=b[0];t1+=b[1];
    t2+=d[0];t2+=d[1];
    if(t1==t2 &&a==c )cout<<1;
    else cout<<0;
    if(t1==t2 && a==c){
        char x=b[2],y=d[2];
        if(x<='C' && y<='C')cout<<1;
        else if(x>='D' && y>='D')cout<<1;
        else cout<<0;
    }

    else cout<<0;
    if(t1==t2 && a==c){
        char x=b[2],y=d[2];
        if(abs(int(x-y))==1){
            if(x<='C' && y<='C')cout<<1;
            else if(x>='D' && y>='D')cout<<1;
            else cout<<0;
        }
        else cout<<0;
    }
    else cout<<0;
    return 0;
}
