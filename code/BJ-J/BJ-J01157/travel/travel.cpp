#include <bits/stdc++.h>
using namespace std;
int c1,c2,tmp1,tmp2;
string s1,s2;
char c3,c4;
int flag1,flag2,flag3,flag4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    tmp1=s1[0]*10+s1[1];
    tmp2=s2[0]*10+s2[1];
    c3=s1[2];
    c4=s2[2];
    if (c1==c2)
        flag1=1;
    if (flag1 &&(tmp1==tmp2))
        flag2=1;
    if (flag2 && (c3<='C' && c4<='C' || c3>'C' && c4>'C'))
        flag3=1;
    if (flag3 && (char(c3+1)==c4 || char(c4+1)==c3))
        flag4=1;
    printf("%d%d%d%d",flag1,flag2,flag3,flag4);
    return 0;
}
