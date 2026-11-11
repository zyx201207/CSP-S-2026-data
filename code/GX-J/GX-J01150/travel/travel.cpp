#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int b,c,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    cout<<(c1==c2?1:0);
    string tmp1,tmp2;
    tmp1=c1[0]+c1[1];
    tmp2=c2[0]+c2[1];
    b=(tmp1==tmp2?1:0);
    cout<<b;
    c=(s1[2]>='A' and s1[2]<='C' and s2[2]>='A' and s2[2]<='C'?1:0);
    d=(s1[2]>='D' and s1[2]<='F' and s2[2]>='D' and s2[2]<='F'?1:0);
    cout<<(b and (c or d)?1:0);
    cout<<(c and abs(s1[2]-48-(s2[2]-48))==1 or d?1:0);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
