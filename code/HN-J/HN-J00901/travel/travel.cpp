#include <iostream>
#include <string>
using namespace std;
string a,b,c,d;
int a1,b1,b2,c1,d1,d2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    a1=(a[0]-'0')*10+(a[1]-'0');
    c1=(c[0]-'0')*10+(c[1]-'0');
    b1=(b[0]-'0')*10+(b[1]-'0');
    b2=(b[2]-'A');
    d1=(d[0]-'0')*10+(d[1]-'0');
    d2=(d[2]-'A');
    if(a1==c1 && a1!=1 && a1!=16 && c1!=1 && c1!=16){
        cout<<"1";
        if(b1==d1){
            cout<<"1";
            if((d[2]>='A' && d[2]<='C' && b[2]>='A' && b[2] <='C')||(b[2]>='D' && d[2]>='D' && d[2]<='E' && b[2]<='E')){
                cout<<"1";
                if(d2+1==b2 || d2-1==b2 ){
                    cout<<"1";
                }else cout<<"0";
            }else cout<<"00";
        }else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
