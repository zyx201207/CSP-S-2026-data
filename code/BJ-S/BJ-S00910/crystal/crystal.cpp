#include<bits/stdc++.h>
using namespace std;
int n,ans,a[500001];
long long m;
int lby(int sd,long long onl)
{
    int ans=0;
    for(int i=sd;i>0;i--)
    {
        int tmp=a[sd]-a[i];
        if(tmp<=onl)
        {
            onl-=tmp;
            ans+=1;
        }
    }
    return ans;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        ans=max(ans,lby(i,m));
    cout<<ans;
    return 0;
}
