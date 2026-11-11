#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,a,b,n,m,k;
    int sum=0,a1,a2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
        cout<<1;
    else
    {
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(s1.substr(0,2)==s2.substr(0,2))
        cout<<1;
    else
        cout<<0;
    int t=0,t2=0;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]>='A' && s1[i]<='C')
        {
            t=1;
            n=s1[i];
            a1=s1[i]-'0';
        }
    }
    for(int i=0;i<s2.size();i++)
    {
        if(s2[i]>='A' && s2[i]<='C')
        {
            t2=1;
            m=s2[i];
            a2=s2[i]-'0';
        }
    }
    if(t==1 && t2==1)
        cout<<1;
    else
        cout<<0;
    if(n>m)
        swap(n,m);
    if(a1>a2)
        swap(a1,a2);
    if(a2-a1>1 && n!=m)
        cout<<0;
    else
        cout<<1;
    return 0;
}
