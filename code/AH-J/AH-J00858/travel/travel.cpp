#include<bits/stdc++.h>
using namespace std;
string r,r_,x,x_;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r>>r_>>x>>x_;
    if(r==x) cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    if(r_[0]==x_[0]&&r_[1]==x_[1]){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    if((r_[2]<='C'&&x_[2]<='C')||(r_[2]>='D'&&x_[2]>='D')){
        cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }
    if((abs(r_[2]-x_[2])==1) || (r_[2]=='D'&&x_[2]=='F') || (r_[2]=='F'&&x_[2]=='D')){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
