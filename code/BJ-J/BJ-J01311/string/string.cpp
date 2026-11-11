#include <bits/stdc++.h>
using namespace std;
string s;
void b(long long n1,char a)
{
    for(int i=1;i<=n1;i++)
    {
        s+=a;
    }
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long n1;
        cin>>n1;
        char a;
        cin>>a;
        b(n1,a);
    }
    long long l=s.length();
    if(l%2==0)
    {
        for(int i=0;i<=(l-1)/2;i++)
        {
            if(s[i]!=s[l-i-1])
            {
                ans++;
            }
        }
    }
    else
    {
        for(int i=0;i<(l-1)/2;i++)
        {
            if(s[i]!=s[l-i-1])
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
