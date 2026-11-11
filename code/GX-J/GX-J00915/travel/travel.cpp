#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,t1,t2;
    cin>>s1>>s2>>t1>>t2;
    if(s1==t1) cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    if(s2[0]+s2[1]==t2[0]+t2[1]) cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    if(('A'<=s2[2]&&s2[2]<='C'&&'A'<=t2[2]&&t2[2]<='C')||('D'<=s2[2]&&s2[2]<='F'&&'D'<=t2[2]&&t2[2]<='F')) cout<<"1";
    else{
        cout<<"00";
        return 0;
    }
    if(abs(s2[2]-t2[2])==1) cout<<"1";
    else cout<<"0";
    return 0;
}
