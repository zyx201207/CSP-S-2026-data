#include<bits/stdc++.h>
using namespace std;
string s1,s2;
long long a[100005],n,ans=0;
char b[100005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(long long i=1;i<=n;i++)
    {
        s1+=b[i];
        s2+=b[i];
    }
    reverse(s2.begin(),s2.end());
    if(s1==s2){cout<<0;return 0;}
    for(int i=1;i<=n;i++)
    {
        if(s1[i]!=s2[i])
        {
            s2[i]=s1[i];
            ans+=a[i];
        }
    }
    cout<<ans;
    return 0;
}
