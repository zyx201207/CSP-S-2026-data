#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2,s3,s4;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1!=s3){
        cout<<"0000";
        return 0;
    }cout<<1;
    if(s2[0]!=s4[0] or s2[1]!=s4[1]){
        cout<<"000";
        return 0;
    }cout<<1;
    if(s2[2]>='D' xor s4[2]>='D'){
        cout<<"00";
        return 0;
    }cout<<1;
    if((s2[2]>='D' and s4[2]>='D') or (s2[2]<'C' and s4[2]<'C') or (s2[2]>'A' and s4[2]>'A'))cout<<1;
    else cout<<0;
    return 0;
}
