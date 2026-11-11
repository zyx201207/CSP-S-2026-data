#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
const int M=5e3+7;
const long long INF=3e18+2e17+9e16;
typedef long long ll;

int T=1;

ll n,d;

ll a[N];

ll shortest[M][M];
ll cnt[M][M];
ll ans;

void dfs(ll x, ll y, ll pres, ll dist)
{
    if(pres==y)
    {
        /*if(shortest[x][y]==0)
        {
            shortest[x][y]=dist;
            cnt[x][y]=1;
        }*/
        if(dist<shortest[x][y])
        {
            shortest[x][y]=dist;
            cnt[x][y]=1;
        }
        else if(dist==shortest[x][y])cnt[x][y]++;
        return;
    }
    for(int i=pres+1;i<=y;i++)
    {
        if(a[i]-a[pres]>d)break;
        dfs(x,y,i,dist+1);
    }
}

int mian()
{
    ans=0;
    /*init*/
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cnt[i][j]=0;
            shortest[i][j]=INF;
        }
    }
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=1;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            dfs(i,j,i,0);
            //<<cnt[i][j]<<" ";
            if(cnt[i][j]==2)ans++;
        }
        //cout<<"\n";
    }
    cout<<ans<<"\n";
    //
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C;
    cin>>C>>T;
    while(T--)
    {
        mian();
    }
    return 0;
}

/*
======CHECK LIST========

file i/o [DONE]
long long [DON'T CARE]
adjust array ranges [DON'T CARE]
calculate time [sth more than O(n^2*2^n)]
calculate space [DON'T CARE]
initialization [DONE]
remove extra outputs [DONE]
check all warnings (Wall) [DON'T CARE AT ALL]

lmz可爱捏

*/
