#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char e,f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c>>e>>b>>d>>f;
    if(a!=b)cout<<"0000";
    else{
        cout<<"1";
        if(c==d){
            cout<<"1";
            if(e-'A'<=2&&f-'A'<=2||e-'A'>2&&f-'A'>2){
                cout<<"1";
                if(e=='A'&&f=='C'||e=='C'&&f=='A')cout<<"0";
                else cout<<"1";
            }
            else{

                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    return 0;
}
