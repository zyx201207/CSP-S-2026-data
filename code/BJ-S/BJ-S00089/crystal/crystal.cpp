#include<bits/stdc++.h>
using namespace std;
const int N=5e5+4;
long long sd[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>sd[i];
    }
    sort(sd+1,sd+1+n);
    int l=1,r=1,ans=0;
    long long cost=0;
    while(l<=n&&r<=n)
    {
        if(cost<=m)
        {
            r++;
            cost+=(sd[r]-sd[r-1])*(r-l);
        }
        else
        {
            l++;
            cost-=(sd[r]-sd[l]);
        }
        if(cost<=m) ans=max(ans,r-l+1);
    }
    cout<<ans<<"\n";
    return 0;
}