#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    mp['A']=1;mp['B']=1;mp['C']=1;
    mp['D']=2;mp['F']=2;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }

    if(s1.substr(0,2)==s2.substr(0,2)) cout<<1;
    else{
        cout<<0<<0<<0;
        return 0;
    }

    if(mp[s1[2]]==mp[s2[2]]) cout<<1;
    else{
        cout<<0<<0;
        return 0;
    }

    if(abs(s2[2]-s1[2])==1) cout<<1;
    else cout<<0;
    return 0;
}
