#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int f1=1,f2=1,f3=1,f4=1;
int check(char s)
{
    if(s>='A'&&s<='C')
    {
        return 1;
    }
    else{
        return 2;
    }
}
int ans(char a,char b)
{
    if(a>='A'&&a<='C'&&b>='A'&&b<='C')
    {
        if(a==b+1||b==a+1)
        {
            return 1;
        }
    }
    if(a>='D'&&a<='E'&&b>='D'&&b<='E')
    {
        return 1;
    }
    return 2;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;

    if(c1!=c3)
    {
        f1=0;
    }
    for(int i=0;i<2;i++)
    {
        if(c2[i]!=c4[i]||f1==0)
        {
            f2=0;
        }
    }

    if(check(c2[2])!=check(c4[2])||f1==0||f2==0)
    {
        f3=0;
    }
    if(ans(c2[2],c4[2])==2||f1==0||f2==0||f3==0)
    {
        f4=0;
    }
    cout<<f1<<f2<<f3<<f4;
    return 0;
}
