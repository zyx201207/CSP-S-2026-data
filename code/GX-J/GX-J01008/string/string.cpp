#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    long long n,ans=0;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        long long a;
        char c;
        cin>>a>>c;
        for(long long i=1;i<=a;i++)
        {
            s+=c;
        }
    }
    long long l=s.size(),k=l-1;
    for(int i=0;i<l/2;i++)
    {
        if(s[i]!=s[k])
        {
            ans++;
        }
        k--;
    }
    cout<<ans;
    return 0;
}
