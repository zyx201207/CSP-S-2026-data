#include<bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
map<char,int> mp;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    mp['A']=mp['B']=mp['C']=1;
    mp['D']=mp['F']=2;
    cin>>a>>a1>>b>>b1;
    if(a==b) cout<<"1";
    else{cout<<"0000"; return 0;}
    if(a1[0]==b1[0]&&a1[1]==b1[1]) cout<<"1";
    else{cout<<"000"; return 0;}
    if(mp[a1[2]]==mp[b1[2]]) cout<<"1";
    else{cout<<"00"; return 0;}
    if((a1[2]=='A'&&b1[2]=='B')||(a1[2]=='B'&&b1[2]=='C')||(a1[2]=='D'&&b1[2]=='F')||(a1[2]=='B'&&b1[2]=='A')||(a1[2]=='C'&&b1[2]=='B')||(a1[2]=='F'&&b1[2]=='D')) cout<<"1";
    else{cout<<"0"; return 0;}
    return 0;
}
