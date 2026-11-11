#include<bits/stdc++.h>
using namespace std;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,t1,s2,t2;
    cin>>s1>>t1>>s2>>t2;
    if(s1==s2)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    string k1=t1.substr(0,2),k2=t2.substr(0,2);
    if(k1==k2)cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    char x1=t1[2],x2=t2[2];
    if(x1>='A'&&x1<='C'&&x2>='D'&&x2<='E' || x1>='A'&&x1<='C'&&x2>='D'&&x2<='E'){
        cout<<"00";
        return 0;
    }else cout<<1;
    if(int(x1)+1==(int)x2||int(x1)-1==int(x2)){
        cout<<1;
    }else cout<<"0";
    return 0;
}

