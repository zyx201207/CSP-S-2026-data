#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a1,b1,a2,b2;
char aa,bb;
bool flag1,flag2,flag3,flag4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for (int i=0;i<c1.size();i++)
    {
        a1=a1*10+(c1[i]-'0');
        a2=a2*10+(c2[i]-'0');
    }
    if(a1==a2) flag1=1;
    else flag1=0;
    for (int i=0;i<s1.size()-1;i++)
    {
        b1=b1*10+(s1[i]-'0');
        b2=b2*10+(s2[i]-'0');
    }
    if(flag1 && b1==b2) flag2=1;
    else flag2=0;
    aa=s1[s1.size()-1],bb=s2[s2.size()-1];
    if(flag2 && ((aa<='C' && bb<='C') || (aa>'C' && bb>'C'))) flag3=1;
    else flag3=0;
    if(flag3 && abs((aa-'A')-(bb-'A'))==1) flag4=1;
    else flag4=0;
    cout<<flag1<<flag2<<flag3<<flag4;
    return 0;
}
