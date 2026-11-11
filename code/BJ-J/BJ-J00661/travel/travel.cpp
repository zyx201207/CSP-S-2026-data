#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1()
{
    if (c1==c2)
        return 1;
    return 0;
}
bool f2()
{
    if (f1())
    {
        if (s1[0]==s2[0]&&s1[1]==s2[1])
            return 1;
    }
    return 0;
}
bool f3()
{
    char tmp1=s1[2];
    char tmp2=s2[2];
    if (f2())
    {
        if (('A'<=tmp1&&tmp1<='C')&&('A'<=tmp2&&tmp2<='C'))
            return 1;
        if (('D'<=tmp1&&tmp1<='F')&&('D'<=tmp2&&tmp2<='F'))
            return 1;
    }
    return 0;
}
bool f4()
{
    int tmp1=s1[2]-'A',tmp2=s2[2]-'A';
    if (f3())
    {
        if (abs(tmp1-tmp2)==1)
            return 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if (f1()) cout<<1;
    else cout<<0;
    if (f2()) cout<<1;
    else cout<<0;
    if (f3()) cout<<1;
    else cout<<0;
    if (f4()) cout<<1;
    else cout<<0;
    return 0;
}
