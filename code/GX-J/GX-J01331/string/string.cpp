#include<bits/stdc++.h>
using namespace std;
long long n,len,ans;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        int r;
        string l;
        cin>>r>>l;
        for(long long j=1;j<=r;j++)
        {
            s+=l;
        }
    }
    len=s.size();
    for(long long i=0,j=len-1;i<len/2;i++,j--)
    {
        if(s[i]!=s[j])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
