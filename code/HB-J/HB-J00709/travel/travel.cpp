#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string xzw,rzw;
    int xcx,rcx;
    cin>>xcx>>xzw>>rcx>>rzw;
    int aa=xzw[0]*1000+xzw[1];
    int bb=rzw[0]*1000+rzw[1];
    if(xcx!=rcx)cout<<"0000";
    else if(aa!=bb)cout<<"1000";
    else{
        char a=xzw[2];
        char b=rzw[2];
        if((a=='D'&&b=='F')||(a=='F'&&b=='D')||(a<='C'&&b<='C'&&abs(a-b)==1))cout<<"1111";
        else cout<<"1110";
    }
    return 0;
}
