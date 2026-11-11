#include<bits/stdc++.h>
using namespace std;
long long n,len,cnt=0;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        long long t;
        char c;
        cin>>t>>c;
        string a;
        for(long long j=0;j<t;j++) a+=c;
        len+=t;
        s+=a;
    }
    for(long long i=0;i<len/2;i++)
    {
        if(s[i]!=s[len-i-1]) cnt++;
    }
    cout<<cnt;
    return 0;
}
