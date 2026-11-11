#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,l=0,r=0,t=0;
    string s,z;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long a;
        char b;
        cin>>a>>b;
        for(int j=r;j<=r+a;j++)
        {
            s[j]=b;
        }
        r+=a;
    }
    for(int i=s.size();i>0;i--)
    {
        z[t]=s[i];
        t++;
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=z[i])
        {
            l++;
        }
    }
    cout<<l;
    return 0;
}
