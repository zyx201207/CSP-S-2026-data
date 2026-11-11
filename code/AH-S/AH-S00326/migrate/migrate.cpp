#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+5;
long long c,t,n,mindep=LONG_LONG_MAX;
long long d,k,ans;
long long a[N];
void dfs(long long s,long long t,long long dep)
{
    if(dep>mindep) return ;
    if(s==t) 
    {
        // cout<<dep<<endl;
        if(dep==mindep) k++;
        else if(dep<mindep) 
        {
            k=0,mindep=dep;
        }
        return ;
    }
    for(int i=s+1;i<=t;i++)
    {
        if(a[i]-a[s]<=d) dfs(i,t,dep+1);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        memset(a,0,sizeof a);
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n-3;i++)
            for(int j=i+3;j<=n;j++)
            {
                dfs(i,j,0);
                if(k==1) ans++;
                k=0,mindep=LONG_LONG_MAX;
            }
        cout<<ans<<"\n";
        ans=0;
    }
    //Oct31==Dec25?
    return 0;
}