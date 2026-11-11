#include<bits/stdc++.h>
using namespace std;
int tp(string s1,string s2){
    for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]) return 0;
    }
    return 1;
}
int tc(string s1,string s2){
    if(s1[2]=='D'&&s2[2]=='E'||s1[2]=='E'&&s2[2]=='D') return 1;
    if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')return 1;
    return 0;
}
int xl(string s1,string s2){
    if(s1[2]==s2[2]+1||s1[2]==s2[2]-1)return 1;
    if(s2[2]==s1[2]+1||s2[2]==s1[2]-1)return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]!=c2[0]&&c1[1]!=c2[1]) {
        cout<<0000;
        return 0;
    }else cout<<1;
    cout<<tp(s1,s2)<<tc(s1,s2)<<xl(s1,s2);
    return 0;
}
