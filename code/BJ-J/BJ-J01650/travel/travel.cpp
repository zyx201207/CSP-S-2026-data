#include <bits/stdc++.h>
using namespace std;
map<char,char> mp;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    mp['A']='l';
    mp['B']='l';
    mp['C']='l';
    mp['D']='r';
    mp['F']='r';
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<'1';
    else cout<<'0';
    if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]) cout<<'1';
    else cout<<'0';
    if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && mp[s1[2]]==mp[s2[2]]) cout<<'1';
    else cout<<'0';
    if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && mp[s1[2]]==mp[s2[2]] && ((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C') || (s1[2]=='B' && s2[2]=='A') || (s1[2]=='C' && s2[2]=='B') || (s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D'))) cout<<'1';
    else cout<<'0';
    return 0;
}
