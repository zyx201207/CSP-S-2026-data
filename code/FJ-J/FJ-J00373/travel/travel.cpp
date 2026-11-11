#include <bits/stdc++.h>
using namespace std;
int c1,s1;
string c2,s2;
int main()
{
    cin>>c1<<s1<<c2<<s2;
    if(c1 == s1){
        cout<<"1";
    else cout<<"0";
    int cc = (c2[0]-'0')*10 + (c2[1]-'0');
    int ss = (s2[0]-'0')*10 + (c2[1]-'0');
    if(cc == ss){
        cout<<"1";
        if(c2[2] == s2[2]) cout<<"1";
        else cout<<"0";
    }else{
        cout<<"0";
        cout<<"0";
    }
    if(((c2[2]-'0')-(s2-'0'))*((c2[2]-'0')-(s2[2]))==1) cout<<"1";
    else cout<<"0";
    return 0;
}