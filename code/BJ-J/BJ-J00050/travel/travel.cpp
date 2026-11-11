#include <bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
map<char,int> mp;
void init(){
    mp['A']=1;
    mp['B']=1;
    mp['C']=1;
    mp['D']=2;
    mp['F']=2;
    return ;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    init();
    cin>>a1>>a2>>b1>>b2;
    if(a1!=b1){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(a2[0]!=b2[0] || a2[1]!=b2[1]){
        cout<<"000";
        return 0;
    }
    cout<<1;
    if(mp[a2[2]]!=mp[b2[2]]){
        cout<<"00";
        return 0;
    }
    cout<<1;
    char a=a2[2];
    char b=b2[2];
    if((a=='A' && b=='B') || (a=='B' && b=='C') || (a=='D' && b=='F')){
        cout<<1;
        return 0;
    }
    cout<<0;
    return 0;
}
