#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans=0,sum=0;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        char y;
        cin>>x>>y;
        sum+=x;
        for(int j=1;j<=x;j++)
            s+=y;
    }
    for(int i=0;i<sum/2;i++)
    {
        if(s[i]!=s[sum-i-1])
            ans++;
    }
    cout<<ans;
    return 0;
}
