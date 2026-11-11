#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int e,f,g,h;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        e=1;
        if(b[0]+b[1]==d[0]+d[1]){
            f=1;
            if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D')){
                g=1;
                if(abs(b[2]-d[2])==1)h=1;
            }
        }
    }
    cout<<e<<f<<g<<h;
    return 0;
}
