#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main (){
   freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
    string st,sr,se,sw;
    cin>>st>>sr>>se>>sw;
    bool falg = false;
    if(st == se){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(sr[0]==sw[0]&&sr[1] == sw[1]){
        cout<<1;
        falg = true;
    }else cout<<0;


    if(sr[2]<='C'&&sw[2]<='C'&&falg){
        cout<<1;
    }else if(sr[2] >= 'D'&&sw[2]>='D'&&falg){
        cout<<1;
    }
    else cout<<0;


    if(falg&&sr[2] - sw[2] == 1||sw[2] - sr[2] == 1&&falg){
        if(sr[2] == 'C'&&sw[2] == 'D'||sw[2] == 'C'&&sr[2] =='D')cout<<0;
        else cout<<1;
    }
    else cout<<0;
    return 0;
}

