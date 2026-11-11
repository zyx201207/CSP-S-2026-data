#include <bits/stdc++.h>
using namespace std;
long long c[3],p[3];
char s[3];
int ch()
{
    if(c[1]==c[2])
    {
        cout<<1;
        return 1;
    }
    else{
        cout<<0;
        return 0;
    }
}

int ph()
{
    if(p[1]==p[2])
    {
        cout<<1;
        return 1;
    }
    else{
        cout<<0;
        return 0;
    }
}

int zh1()
{
    if((s[1]+1)==s[2] || (s[2]+1)==s[1])
    {
        cout<<1;
        return 1;
    }
    else
    {
        cout<<0;
        return 0;
    }
}



int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long n;
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    for(long long i=0;i<=1;i++)
    {
        c[1]*=10;
        c[1]+=(c1[i]-'0');
        c[2]*=10;
        c[2]+=(c2[i]-'0');
    }
    n=ch();
    if(n==0){
        cout<<0<<0<<0;
        return 0;
    }

    p[1]+=(s1[0]-'0');
    p[1]*=10;
    p[1]+=(s1[1]-'0');
    p[2]+=(s2[0]-'0');
    p[2]*=10;
    p[2]+=(s2[1]-'0');
    n=ph();
    if(n==0){
        cout<<0<<0;
        return 0;
    }

    s[1]=s1[2];
    s[2]=s2[2];

    if((s[1]>='A' && s[1]<='C' && s[2]>='A' && s[2]<='C'))
    {
        cout<<1;
        zh1();
        return 0;
    }
    else if(((s[1]=='D' && s[2]=='F')) || (s[1]=='F' && s[2]=='D'))
    {
        cout<<1<<1;
    }
    else
    {
        cout<<0;
        cout<<0;
    }
    return 0;
}
