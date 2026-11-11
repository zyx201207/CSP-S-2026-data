#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool vis[200005];
ll n,m,a[200005],ans;
bool b[200005][30];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=0;j<30;j++)
        {
            if(a[i]&(1<<j))
            {
                b[i][j]=1;
            }
        }
        vis[i]=1;
    }
    for(int j=29;j>=0;j--)
    {
        ll cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(b[i][j]&vis[i])cnt++;
        }
        if(cnt<m)
        {
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if((b[i][j]&vis[i])==0)vis[i]=0;
        }
        ans|=(1<<j);
    }
    cout<<ans<<endl;
    return 0;
}
