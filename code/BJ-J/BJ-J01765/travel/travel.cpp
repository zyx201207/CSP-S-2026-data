#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool aa,bb,cc,dd;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        aa=1;
        if(b[0]==d[0]&&b[1]==d[1]){
            bb=1;
            if((b[2]-'A'<=2&&d[2]-'A'<=2)||(abs(b[2]-'E')==1)&&(abs(d[2]-'E')==1))
            {
                cc=1;
                if((b[2]-'A'<=2&&d[2]-'A'<=2)&&abs(b[2]-d[2])==1){
                    dd=1;
                }
                else if((abs(b[2]-'E')==1)&&(abs(d[2]-'E')==1)&&b[2]!=d[2]){
                    dd=1;
                }
            }
        }
    }
    if(aa)
        cout<<1;
    else
        cout<<0;
    if(bb)
        cout<<1;
    else
        cout<<0;
    if(cc)
        cout<<1;
    else
        cout<<0;
    if(dd)
        cout<<1;
    else
        cout<<0;
    return 0;
}