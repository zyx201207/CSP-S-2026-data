#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string aa,bb;
    cin>>a>>aa>>b>>bb;
    if(a==b){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(aa[0]+aa[1]==bb[0]+bb[1]){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if(aa[2]<='C'&&bb[2]<='C'){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(abs(aa[2]-bb[2])==1){
        cout<<1;
    }else{
        cout<<"0";
        return 0;
    }
    return 0;
}