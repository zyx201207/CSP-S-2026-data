#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    string g;
    cin>>s;
    cin>>g;
    string f;
    int j=0;
    for(int i=0;i<=s.size()+g.size();i++)
    {
        if(i<=s.size())
        {
            f[i]=s[i];
        }
        if(i>s.size())
        {
            f[i]=g[i];
        }
    }
    string a,b;
    for(int i=f.size();i>0;i--)
    {
        a[i]=f[i];
    }
    for(int i=0;i<f.size();i++)
    {
        b[i]=f[i];
    }
    if(a==b)
    {
        cout<<0;
    }
    return 0;
}
