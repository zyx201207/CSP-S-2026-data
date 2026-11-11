#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    char c;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a>>c;
        for(int j=1;j<=a;j++)
        {
            s+=c;
        }
    }
    string s2;
    for(int i=0;i<s.size();i++)
    {
        s2+=s[s.size()-i-1];
    }
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        if(s2[i]!=s[i])
        {
            s[i]=s2[i];
            ans++;
        }
    }
    cout<<ans/2;
    return 0;
}
