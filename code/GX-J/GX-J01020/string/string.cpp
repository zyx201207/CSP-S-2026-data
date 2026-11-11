#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans=0,m=0;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long t;
        cin>>t;
        char c;
        cin>>c;
        m+=t;
        for(int j=1;j<=t;j++)
        {
            s+=c;
        }
    }
    long long k=m;
    for(long long i=0;i<=(m-1)/2;i++)
    {
        k--;
        if(s[i]!=s[k])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
