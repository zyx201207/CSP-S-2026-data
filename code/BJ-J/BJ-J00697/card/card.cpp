#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],s1[300005],s2[300005],ok[500005],sum[300005],be[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s1[a[i]]++;
    }
    int last=0,last_val=0;
    for(int i=1;i<=n;i++)
    {
        s2[a[i]]++;
        if(a[i]==last_val)
        {
            last=0;
            last_val=0;
        }
        if(s1[a[i]]!=s2[a[i]])
        {
            last=i;
            last_val=a[i];
        }
        else ok[i]=last;
        sum[a[i]]+=(i-max(ok[i],be[a[i]]));
        be[a[i]]=i;
    }
    for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
    return 0;
}
