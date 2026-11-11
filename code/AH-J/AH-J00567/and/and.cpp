#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m,ans;
ll a[N],f[N];
void dfs(int k,int x,int sum)
{
    if(k>m)
    {
        ans=max(ans,sum);
       // cout<<"______:"<<ans<<'\n';
        return ;
    }
    int s=sum;
    for(int i=x;i<=n;i++)
    {
            s=sum;
           //cout<<x<<" "<<i<<" "<<s<<"&"<<a[i]<<" ";
          // cout<<sum<<' ';
            if(x==1) s=a[i];
            else s=s&a[i];
           // cout<<s<<'\n';

            dfs(k+1,i+1,s);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(f,0,sizeof(f));

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    ans=-1;

    dfs(1,1,0);

    cout<<ans;
    return 0;
}
