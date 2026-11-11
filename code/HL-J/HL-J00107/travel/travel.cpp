#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,b1,a2,b2;char a3,b3;
    cin>>a1>>b1>>a3>>a2>>b2>>b3;
    if(a1==a2){
        cout<<1;
        if(b1==b2){
            cout<<1;
            if((a3=='A'||a3=='B'||a3=='C')&&(b3=='A'||b3=='B'||b3=='C')){
                cout<<1;
                if(a3=='A'&&b3=='B'){
                    cout<<1;return 0;
                }if(a3=='B'){
                    cout<<1;return 0;
                }if(a3=='C'&&b3=='B'){
                    cout<<1;return 0;
                }cout<<0;
            }else if((a3=='D'||a3=='F')&&(b3=='D'||b3=='F')){
                cout<<11;return 0;
            }else{
                cout<<"00";return 0;
            }
        }else{
            cout<<"000";
            return 0;
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
