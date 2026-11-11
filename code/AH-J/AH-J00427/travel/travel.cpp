#include<bits/stdc++.h>
using namespace std;
string c1;
string s1;
string c2;
string s2;
int zw(char ch)
{
    if(ch=='A'||ch=='B'||ch=='C')
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
void solve1()
{
    if(c1==c2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return ;
}
void solve2()
{
    string a="";
    string b="";
    a+=s1[0];
    a+=s1[1];
    b+=s2[0];
    b+=s2[1];
    if(c1==c2&&a==b)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return ;
}
void solve3()
{
    string a="";
    string b="";
    a+=s1[0];
    a+=s1[1];
    b+=s2[0];
    b+=s2[1];
    char ch1=s1[2];
    char ch2=s2[2];
    if(c1==c2&&a==b&&zw(ch1)==zw(ch2))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return ;
}
void solve4()
{
    string a="";
    string b="";
    a+=s1[0];
    a+=s1[1];
    b+=s2[0];
    b+=s2[1];
    char ch1=s1[2];
    char ch2=s2[2];
    if(c1==c2&&a==b&&zw(ch1)==zw(ch2))
    {
        if(zw(ch1)==1)
        {
            if(ch1=='A'&&ch2=='B')
            {
                cout<<1;
            }
            else  if(ch1=='B'&&ch2=='C')
            {
                cout<<1;
            }
            else  if(ch1=='B'&&ch2=='A')
            {
                cout<<1;
            }
            else  if(ch1=='C'&&ch2=='B')
            {
                cout<<1;
            }
            else
            {
                cout<<0;
            }
        }
        else
        {
            cout<<1;
        }
    }
    else
    {
        cout<<0;
    }
    return ;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    solve1();
    solve2();
    solve3();
    solve4();
    return 0;
}
