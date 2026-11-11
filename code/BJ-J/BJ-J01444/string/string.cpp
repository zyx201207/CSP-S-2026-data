#include<bits/stdc++.h>
using namespace std;
string s;
bool hui(string x)
{
    for(int i=0;i<x.size()/2;i++)
    {
        if(x[i]!=x[x.size()-i-1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long ai;
        string c;
        cin>>ai;
        cin>>c;
        for(int j=1;j<=ai;j++)
        {
            s+=c;
        }
    }

    if(hui(s))
    {
        cout<<0;
        return 0;
    }
    long long ans=0;
    string d;
    for(int i=s.size()-1;i>=0;i--)
    {
        d+=s[i];
    }
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=d[i])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}