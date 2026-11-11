#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool flag=1;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else{
        cout<<0;
        flag=0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&flag) cout<<1;
    else{
        cout<<0;
        flag=0;
    }
    if(flag&&(((s1[2]-'0' >= 'D' && s2[2]-'0'>='D')||(s1[2]-'0' <= 'C' && s2[2]-'0'<='C')))){
        cout<<1;
    }
    else{
        cout<<0;
        flag=0;
    }
    if(flag&&(((s1[2]-'0')-(s2[2]-'0')==1)||((s2[2]-'0')-(s1[2]-'0')==1))) cout<<1;
    else{
        cout<<0;
    }
    return 0;
}
