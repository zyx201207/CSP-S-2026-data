#include<iostream>
#include<algorithm>
#include<list>
#include<cstdio>
#include<iomanip>
#include<vector>
#include<queue>
#include<set>
#define use_n3 1
#define test_is_A 0
#define test_is_C 0
#define RUN_BIG_AS_C 1
using namespace std;
const int N=2000005,N2=605,N3=1000005,Z=22;
int n,c,t;
typedef long long ll;
ll d,a[N];
ll ans;
int lst[N],pole[N];
//int cnt0[N],cnt1[N];
//vector<int> nxt[N];

int dp1[N2][N2];
ll dp2[N2][N2];

//int z[N3];
//int f[N3][Z],g[N3][Z],h[N3][Z];
void MAIN()
{
    cin>>n>>d;
    int cur=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        while(a[i]-a[cur]>d&&cur<i) cur++;
        lst[i]=cur;
        //pole[i]=pole[lst[i]];
        //if(i!=cur)nxt[cur].push_back(i);
        //z[i]=z[lst[i]]+1;
    }
    /*the doublelock structure:(==> means lst,C=lst[lst[...[lst[i]]...]])
    A<==B<==C B<D<C A<==D
    all connected and before B contributes,counted in cnt0.

    the overjump structure:
    A<==B<==C A<D<B<E<C D<==E
    all after/equal D and before B contributes,counted in cnt1.
    */
    //ERROR: it must have exactly2 paths

    if(use_n3&&c<=6&&n<=300)
    {
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(lst[j]<=i) dp1[i][j]=1,dp2[i][j]=1/*,cout<<i<<' '<<j<<'\n'*/;
                else dp1[i][j]=0,dp2[i][j]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<i;j++)
                for(int k=i+1;k<=n;k++)
                    if(dp1[j][i]&&dp1[i][k])
                    {
                        if(!dp1[j][k]||dp1[j][k]>dp1[j][i]+dp1[i][k]) dp1[j][k]=dp1[j][i]+dp1[i][k],dp2[j][k]=dp2[j][i]*dp2[i][k];
                        else if(dp1[j][k]==dp1[j][i]+dp1[i][k]&&dp2[i][j]<=2) dp2[j][k]++;
                        //cout<<i<<' '<<j<<' '<<k<<' '<<dp1[j][k]<<' '<<dp2[j][k]<<'\n';
                    }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                ans+=dp2[i][j]==2;
    }
    else if((11<=c&&c<=12)||test_is_A)
    {
        if(d<2*(a[2]-a[1])) cout<<"0\n";
        else
        {
            ll x=d/(a[2]-a[1]);
            cout<<max(0ll,n+1-2*x)<<'\n';
        }
        return;
    }
    /*else if((13<=c&&c<=18)||test_is_C||RUN_BIG_AS_C)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=20;j++) f[i][j]=g[i][j]=h[i][j]=i;
            z[i]=lst[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            if(lst[i]!=i) z[i]=z[lst[i]]+1;
            for(int j=1;j<=z[i];j++)
            {
                f[i][j]=f[lst[i]][j-1];
                g[i][j]=g[lst[i]][j-1];
                h[i][j]=h[lst[i]][j-1];
                if(i!=lst[i])g[i][j]=min(f[lst[i]+1][j-1],g[i][j]);
                if(i!=lst[i])h[i][j]=min(g[lst[i]+1][j-1],g[i][j]);
                if(i!=lst[i]&&i!=lst[i]+1)h[i][j]=min(f[lst[i]+2][j-1],g[i][j]);
                ans+=min(f[i][j-1],h[i][j])-g[i][j];
            }
        }
    }*/
    else{}


    cout<<ans<<'\n';
    for(int i=1;i<=n;i++)
    {
        //cnt0[i]=cnt1[i]=0;
        lst[i]=0;
        //pole[i]=0;
        //nxt[i].clear();
        //for(int j=1;j<=z[i];j++)
        //    f[i][j]=g[i][j]=h[i][j]=0x3f3f3f3f;
        //z[i]=0;
    }
    ans=0;
}
int main()
{
    //freopen("/home/rdfz/migrate/migrate5.in","r",stdin);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>c>>t;
    while(t--) MAIN();
    cout.flush();
    return 0;
}