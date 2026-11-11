#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
string s[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i]>>a[i];
        ans+=a[i];
    }
    int cnt=1;
    for(int i=2;i<=n;i++)
    {
        if(s[i]==s[i-1])
        {
            cnt++;
        }
    }
    if(cnt==n)
    {
        cout<<0;
        return 0;
    }
    return 0;
}