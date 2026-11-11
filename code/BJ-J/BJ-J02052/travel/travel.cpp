#include<bits/stdc++.h>
using namespace std;

string c2,s2,c1,s1,s;

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>c1>>s1>>c2>>s2;
    int char c=s1[2]-'0';
    int char c3=s2[2]-'0';
    if(c1!=c2) s="0000";
    else if(s1[0]!=s2[0]||s1[1]!=s2[1]) s="1000";
    else if(c3>='D'&&c<='C'||c>='D'&&c3<='C') s="1100";
    else if(c3=='C'&&c=='A'||c=='C'&&c3=='A') s="1110";
    else s="1111";
    cout<<s;
    return 0;
}
