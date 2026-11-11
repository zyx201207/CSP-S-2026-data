#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1!=s3){
        cout<<"0000"<<"\n";
        return 0;
    }
    cout<<"1";
    if(s2[0]!=s4[0] or s2[1]!=s4[1]){
        cout<<"000"<<"\n";
        return 0;
    }
    cout<<"1";
    if(s2[2]>='A' and s2[2]<='C' and s4[2]>='A' and s4[2]<='C'){
        cout<<"1";
    }else{
        if(s2[2]>='D' and s2[2]<='F' and s4[2]>='D' and s4[2]<='F'){
            cout<<"1";
        }else{
            cout<<"00"<<"\n";
            return 0;
        }
    }
    if(s2[2]==s4[2]+1 or s2[2]==s4[2]-1){
        cout<<"1"<<"\n";
    }else{
        cout<<"0"<<"\n";
    }
    return 0;
}
