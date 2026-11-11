#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2,s="0000";
    cin>>c1>>s1>>c2>>s2;

    if(c1==c2){
        s="1000";
    }else{
        cout<<s;
        return 0;
    }

    if(s1[0]==s2[0] && s1[1]==s2[1]){
        s="1100";
    }else{
        cout<<s;
        return 0;
    }

    if((((s1[2]>='A' && s1[2]<='C') && (s2[2]!='D' && s2[2]!='E')) || (s1[2]>='D' && s1[2]<='E') && (s2[2]=='D' || s2[2]=='E')) || ((s2[2]>='A' && s2[2]<='C') && (s1[2]!='D' && s1[2]!='E')) || ((s1[2]>='D' && s1[2]<='E') && (s2[2]=='D' || s2[2]=='E'))){
        s="1110";
        if(s1[2]-1==s2[2] || s1[2]+1==s2[2]){
            s="1111";
        }else{
            cout<<s;
            return 0;
        }
    }else{
        cout<<s;
        return 0;
    }
    cout<<s;
    return 0;
}

