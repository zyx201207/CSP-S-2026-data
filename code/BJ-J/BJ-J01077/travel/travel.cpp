#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    int f=true;
    for(int i=0;i<2;i++){
        if(a[i]!=c[i]) f=false;
    }
    if(f==false) {
        cout<<"0000";

    }else {
        cout<<1;
        f=true;
        for(int i=0;i<2;i++){
            if(b[i]!=d[i])f=false;
        }
        if(f==false){
            cout<<"000";
        }else{
            cout<<1;
            if((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='E'&&d[2]>='D'&&d[2]<='E')) {
                cout<<1;
                if(abs(((int)b[2])-((int)d[2]))==1&& !((b[2]=='C'&&d[2]=='D')||d[2]=='C'&&b[2]=='D')) cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
    }
    return 0;
}