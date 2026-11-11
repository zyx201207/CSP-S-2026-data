#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    string c1,c2,s1,s2;
    long long h1,h2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }h1=(s1[0]-'0')*10+(s1[1]-'0'),h2=(s2[0]-'0')*10+(s2[1]-'0');
    if(h1==h2){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }if(abs(s1[2]-s2[2])==1){
        cout<<"1";
    }else{
        cout<<"0";
        return 0;
    }
    return 0;
}
