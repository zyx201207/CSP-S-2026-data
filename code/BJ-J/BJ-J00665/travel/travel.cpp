#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cr>>sr>>cx>>sx;
    if(cr==cx){
        cout<<1;
        if(sr[0]==sx[0] and sr[1]==sx[1]){
            cout<<1;
            char r=sr[2],x=sx[2];
            if(((r=='A' or r=='B' or r=='C') and (x=='A' or x=='B' or x=='C')) or ((x=='D' or x=='E') and (r=='D' or r=='E'))){
                cout<<1;
                if(char(r+1)==x or char(x+1)==r){
                    cout<<1;
                }else{
                    cout<<0;
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
}
