#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
map<char,int> mp;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    mp['A']=1;
    mp['B']=1;
    mp['C']=1;
    if(a1==b1)cout<<1;
    else cout<<0;
    if(a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1]){cout<<1;}
    else {cout<<0;}
    if(a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1]&&mp[a2[2]]==mp[b2[2]]){cout<<1;}
    else {cout<<0;}
    if(a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1]&&mp[a2[2]]==mp[b2[2]]&&(a2[2]-1==b2[2]||a2[2]+1==b2[2])){cout<<1;}
    else {cout<<0;}
    return 0;
}
