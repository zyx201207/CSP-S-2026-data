#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c1,c2;
    str s1,s2;
    cin>>c1>>s1>>c2>>s2;
    bool car=c1==c2;
    bool pai=s1[0]==s2[0]&&s1[1]==s2[1];
    bool ce=false;
    if((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F'))  ce=true;
    else if(
        !
        (
            (s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F')
            ||
            (s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s1[2]=='F')
        )
    ) ce=true;
    if(!car)cout<<"0000";
    else cout<<(c1==c2?"1":"0")  <<(pai?"1":"0")
        <<(pai&&ce?"1":"0") <<(pai&&ce&&(((s1[2]+1==s2[2])||s2[2]+1==s1[2])&&(!(s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='D'))));
    return 0;
}