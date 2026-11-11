#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2,k;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)k+="1";
    else k+="0";

    if(s1.substr(0,2)==s2.substr(0,2)&&k=="1")k+="1";
    else k+="0";

    if(k=="11"&&(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))))k+="1";
    else k+="0";

    if(k=="111"&&abs(s1[2]-s2[2])==1)k+="1";
    else k+="0";

    cout<<k;
    return 0;
}
