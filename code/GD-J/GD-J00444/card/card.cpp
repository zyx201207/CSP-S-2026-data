#include<bits/stdc++.h>
using namespace std;
long long n,m,a[510000],b[510000],s[510000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        s[a[i]]++;
        b[a[i]]=i;
    }
    for(long long i=1;i<=n;i++)
    {
        if(b[a[i]]==i)
        {
            s[a[i+1]]+=s[a[i]];
        }
    }
    for(long long i=1;i<=m;i++)
    {
        cout<<s[i]<<" ";
    }
    return 0;
}
