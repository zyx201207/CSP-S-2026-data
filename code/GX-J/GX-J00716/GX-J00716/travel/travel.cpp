#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int ra,xa;
    int f=0;
    string rb,xb,ans="";
    cin>>ra>>rb>>xa>>xb;
    if(ra==xa){
        ans+='1';
    }else{
        ans+='0';
        cout<<"0000";
    }
    char rba=rb[0];
    char rbb=rb[1];
    char xba=xb[0];
    char xbb=xb[1];
    char rbc=rb[2];
    char xbc=xb[2];

    if(xba==rba and xbb==rbb){
        ans+='1';
    }else{
        ans+='0';
        cout<<ans<<"00";
    }
    if((((rbc=='A' or rbc=='B' or rbc=='C' ) and (xbc=='A' or xbc=='B' or xbc=='C'))) or (((rbc=='D' or rbc=='E' ) and (xbc=='D' or xbc=='E' )))){
        ans+='1';
    }else{
        ans+='0';
        cout<<ans<<"0";
    }
    ans+='0';

    cout<<ans;
    return 0;
}



