#include <bits/stdc++.h>
using namespace std;
long long n,cnt;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    cin>>n;
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int x;char c;
        cin>>x>>c;
        for(int j=1;j<=x;j++)
        {
            s+=c;
        }
    }
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-i-1]) cnt++;
    }
    cout<<cnt;
    return 0;
}
