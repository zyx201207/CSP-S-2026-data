#include<bits/stdc++.h>
using namespace std;
string sr1,sr2,sx1,sx2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>sr1>>sr2>>sx1>>sx2;
    if(sr1!=sx1) cout<<"0000";
    else if(sr2.substr(0,2)==sx2.substr(0,2)){
        cout<<11;
        if(((sr2[2]>='A'&&sr2[2]<='C')&&(sx2[2]>='A'&&sx2[2]<='C'))||((sr2[2]>='D'&&sr2[2]<='F')&&(sx2[2]>='D'&&sx2[2]<='F'))) cout<<1;
        else cout<<0;
        if((sr2[2]>='A'&&sr2[2]<='C')&&(sx2[2]>='A'&&sx2[2]<='C')){
            if(sr2[2]==sx2[2]+1||sx2[2]==sr2[2]+1){cout<<1;}
            else cout<<0;
        }
        else if((sr2[2]>='D'&&sr2[2]<='F')&&(sx2[2]>='D'&&sx2[2]<='F')){
            cout<<1;
        }
        else cout<<0;
    }
    else cout<<1000;
    return 0;
}
