#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string a,b,c,d;
cin>>a>>b>>c>>d;
    if(a==c){
    cout<<"1";
    }else{
    cout<<"0";
    }if(b[1]==d[1]&&b[2]==d[2]){
    cout<<"1";}
    else{
    cout<<"0";
    }if(b[3]=='C'&& d[3]=='D'){
    cout<<"0";
    }else{
    cout<<"1";
    }if(b[3]+1==d[3]||b[3]-1==d[3]){
    cout<<"1";
    }else{
    cout<<"0";
    }
    return 0;
}
