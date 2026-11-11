#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string a="";
    string b;
    unsigned long long n,m,ans=0;
    cin>>n;
    for(unsigned long long i=1;i<=n;i++)
    {
        cin>>m>>b;
        for(unsigned long long j=1;j<=m;j++)
        {
            a+=b;
        }
    }
    for(unsigned long long i=0;i<a.size()/2;i++)
    {
        if(a[i] != a[a.size()-i])
        {
            ans++;
        }
    }
    cout<<ans;
}
