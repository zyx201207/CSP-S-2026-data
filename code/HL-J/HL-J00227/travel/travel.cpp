#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    char e,f;
    cin>>a>>b>>e>>c>>d>>f;
    if(a==c)
        cout<<"1";
    else{
            cout<<"0000";
            return 0;
        }
    if(b==d)
        cout<<"1";
    else{
            cout<<"000";
            return 0;
        }
    if((e>='A'&&e<='C'&&f>='A'&&f<='C')||(e>='D'&&e<='F'&&f>='D'&&f<='F')){
            cout<<"1";
        }
    else{
            cout<<"00";
            return 0;
        }
    if(e+1==f||f+1==d)
        cout<<"1";
    else
        cout<<"0";
    return 0;
}
