#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10;
int dis[N][N],cnt[N][N],a[N];
int n,d;
void work()
{
    for(int i=1;i<=n;i++)
    {
        // cout<<i<<":\n";
        cnt[i][i]=1;
        dis[i][i]=0;
        int l=i,r=i,sum=1;
        for(int j=i+1;j<=n;j++)
        {
            while(r<j-1&&(dis[i][r]==dis[i][r+1]||a[j]-a[r]>d)) 
            {
                r++;
                sum+=cnt[i][r];
            }
            while(l<j-1&&(a[j]-a[l]>d||dis[i][l]<dis[i][r])) 
            {
                sum-=cnt[i][l];
                l++;
            }
            if(a[j]-a[r]>d) break;
            // cout<<j<<" "<<l<<" "<<r<<"\n";
            dis[i][j]=dis[i][r]+1;
            cnt[i][j]=sum;
        }
        l=r=i,sum=1;
        for(int j=i-1;j>=1;j--)
        {
            while(l>j+1&&(dis[i][l-1]==dis[i][l]||a[l]-a[j]>d))
            {
                l--;
                sum+=cnt[i][l];
            }
            while(r>j+1&&(a[r]-a[j]>d||dis[i][r]<dis[i][l]))
            {
                sum-=cnt[i][r];
                r--;
            }
            if(a[l]-a[j]>d) break;
            // cout<<j<<" "<<l<<" "<<r<<"\n";
            dis[i][j]=dis[i][l]+1;
            cnt[i][j]=sum;
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++) cout<<dis[i][j]<<" ";
    //     cout<<"\n";
    // }
    int ans=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) 
        {
            // cout<<cnt[i][j]<<" ";
            if(cnt[i][j]==2) ans++;
            cnt[i][j]=dis[i][j]=0;
        }
        // cout<<"\n";
    }
    cout<<ans/2<<"\n";
}
void work1()
{
    int q=d/(a[2]-a[1]);
    cout<<n-2*q+1<<"\n";
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        bool fa=1,fb=0;
        for(int i=2;i<n;i++)
        {
            if(a[i]-a[i-1]!=a[i+1]-a[i]) 
            {
                fa=0;
                break;
            }
        }
        if(fa) work1();
        else work();
    }
}