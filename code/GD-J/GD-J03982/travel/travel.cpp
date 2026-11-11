#include<bits/stdc++.h>
using namespace std;
long long a,b,c,aa,bb,cc;
int k(char x)
{
    if(x<='D')return x-'A'+1;
    else return 5;
}
int f(int x)
{
    if(x<=3)return 0;
    else return 1;
}
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    a=(getchar()-'0')*10+getchar()-'0';
    getchar();
    b=(getchar()-'0')*10+getchar()-'0';
    c=k(getchar());
    getchar();
    aa=(getchar()-'0')*10+getchar()-'0';
    getchar();
    bb=(getchar()-'0')*10+getchar()-'0';
    cc=k(getchar());
    cout<<(a==aa);
    cout<<(a==aa&&b==bb);
    cout<<(a==aa&&b==bb&&f(c)==f(cc));
    cout<<(a==aa&&b==bb&&f(c)==f(cc)&&abs(c-cc)==1);
    return 0;
}