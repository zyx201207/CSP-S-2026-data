#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
bool chick(string a,string b){
    char a1=s1[2];
    char a2=s2[2];
    if (a1=='A' && a2=='B')return true;
    if (a1=='B' && a2=='A')return true;
    if (a1=='A' && a2=='C')return true;
    if (a1=='C' && a2=='A')return true;
    if (a1=='B' && a2=='C')return true;
    if (a1=='C' && a2=='B')return true;
    if (a1=='D' && a2=='F')return true;
    if (a1=='F' && a2=='D')return true;
    return false;
}
bool cc(string a,string b){
    char a1=s1[2];
    char a2=s2[2];
    if ((a1=='D' && a2=='F') || (a1=='F' && a2=='D')) return true;
    if ((a1=='A' && a2=='B') || (a1=='B' && a2=='A')) return true;
    if ((a1=='B' && a2=='C') || (a1=='C' && a2=='B')) return true;
    return false;
 }
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if (c1==c2) cout<<"1";
    else cout<<"0";
    if (c1==c2 && s1[1]-'0' == s2[1] - '0') cout<<"1";
    else cout<<"0";
    if ((c1==c2 && s1[1]-'0' == s2[1] - '0') && chick(s1,s2)) cout<<"1";
    else cout<<"0";
    if (((c1==c2 && s1[1]-'0' == s2[1] - '0') && chick(s1,s2)) && cc(s1,s2)) cout<<"1";
    else cout<<"0";
    return 0;
}
