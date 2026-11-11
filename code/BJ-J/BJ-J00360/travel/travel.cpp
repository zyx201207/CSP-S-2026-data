#include<bits/stdc++.h>
using namespace std;
string my_rc,my_rs,my_xc,my_xs;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>my_rc>>my_rs>>my_xc>>my_xs;
    if(my_rc[0]!=my_xc[0] || my_rc[1]!=my_xc[1]){
        cout<<"0000";
        return 0;
    }
    else{
        cout<<"1";
        if(my_rs[0]!=my_xs[0] || my_rs[1]!=my_xs[1]){
            cout<<"000";
            return 0;
        }
        else{
            cout<<"1";
            if((my_rs[2]<='C' && my_rs[2]>='A' && my_xs[2]<='C' && my_xs[2]>='A') || ((my_rs[2]=='D' || my_rs[2]=='F') && (my_xs[2]=='D' || my_xs[2]=='F'))){
                cout<<"1";
                if(my_rs[2]=='A' && my_xs[2]=='B' || my_rs[2]=='B' && my_xs[2]=='A' || my_rs[2]=='B' && my_xs[2]=='C' || my_rs[2]=='C' && my_xs[2]=='B' || my_rs[2]=='D' && my_xs[2]=='F' || my_rs[2]=='F' && my_xs[2]=='D'){
                    cout<<"1";
                    return 0;
                }
                else{
                    cout<<"0";
                    return 0;
                }
            }
            else{
                cout<<"00";
                return 0;
            }
        }
    }
    return 0;
}
