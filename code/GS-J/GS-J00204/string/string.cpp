#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans=0;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++)
    {
        int sum;
        char g;
        cin>>sum>>g;
        for(int j=1;j<=sum;j++)
        {
            s.push_back(g);
        }
    }
    for(int i=0;i<(s.size()+1)/2;i++)
    {
        if(s[i]!=s[n+1-i])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
