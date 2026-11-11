#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
string h;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long ans=0;
    long long c[200001];
    cin>>n;
    for(long long i=0;i<n;i++)
        {cin>>c[i]>>h;
        for(int j=0;j<c[i];j++)
            s+=h;
        }
    if(s.size()/2==0)
    {
        for(long long i=0;i<s.size()/2;i++)
            if(s[s.size()/2-1+i]!=s[s.size()/2-1-i])
            ans++;
    }
    else
        for(long long i=0;i<=s.size()/2;i++)
            if(s[s.size()/2+i]!=s[s.size()/2-i])
            ans++;
        cout<<ans;
    return 0;
}
