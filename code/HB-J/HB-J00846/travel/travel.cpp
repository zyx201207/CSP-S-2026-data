#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1,s1,c2,s2;
    int v=0,d=0,e,f;
    cin>>c1>>s1>>c2>>s2;
    e=s1;
    f=s2;
    if(e%100==65||e%100==66||f%100==67){
            v=1;
    }
    if(f%100==65||f%100==66||f%100==67){
            d=1;
    }
    if(c1==c2){
        cout<<"1";
        if(e/100==f/100||e/100==f/100||e/100==f/100||e/100==f/100||e/100==f/100){
            cout<<"1";
            if(v==d){
                cout<<"1";
                if(f==e+1||f==e-1){
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
