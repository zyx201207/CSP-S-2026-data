#include<bits/stdc++.h>
using namespace std;
int main()
{
    string c1,s1,z1,c2,s2,z2;
    int ans=0;
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]>='0'&&s1[i]<='9')
        {
            ans++;
        }
        else
        {
            z1=s1.substr(i-ans,ans);
        }
    }
    for(int i=0;i<s2.size();i++)
    {
        if(s2[i]>='0'&&s2[i]<='9')
        {
            ans++;
        }
        else
        {
            z2=s2.substr(i-ans,ans);
        }
    }
    if(c1==c2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(z1==z2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(z1==z2&&(((s1[s1.size()]=='A'||s1[s1.size()]=='B'||s1[s1.size()]=='C')&&
       (s2[s2.size()]=='A'||s2[s2.size()]=='B'||s2[s2.size()]=='C')) ||
       ((s1[s1.size()]=='D'||s1[s1.size()]=='F')&&(s2[s2.size()]=='D'||s2[s2.size()]=='F'))))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(s1[s1.size()]=='A'&&s2[s2.size()]=='B' || s1[s1.size()]=='B'&&s2[s2.size()]=='C'
           || s1[s1.size()]=='D'&&s2[s2.size()]=='F')
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
