#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    long long cnt=0;
    while(n--)
    {
        long long a;
        char c;
        cin>>a>>c;
        cnt+=a;
        for(long long i=1;i<=a;i++)
        {
            s+=c;
        }
    }
    long long ans=0;
    for(long long i=0,j=cnt-1;i<=j;i++,j--)
    {
        if(s[i]!=s[j]) ans++;
    }
    cout<<ans;
    return 0;
}
