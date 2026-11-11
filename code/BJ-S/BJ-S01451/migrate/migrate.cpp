#include<bits/stdc++.h>
using namespace std;
long long n,d,p;
int c,T;
long long a[2000006];
long long ans;
//vector<int> e[2000006];
int e[5005][5005];
int cnt[5005][5005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                e[i][j]=INT_MAX/3,cnt[i][j]=0;
        for(int i=1;i<=n;i++)
        {
            cnt[i][i]=1;
            e[i][i]=0;
            cin>>a[i];
            int p=i-1;
            while(p&&a[i]-a[p]<=d)
            {
                //e[i].push_back(p);
                //e[p].push_back(i);
                e[i][p]=e[p][i]=1;
                cnt[i][p]=cnt[p][i]=1;
                p--;
            }
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(e[i][k]+e[k][j]<e[i][j])
                    {
                        e[i][j]=e[i][k]+e[k][j];
                        cnt[i][j]=cnt[i][k]*cnt[k][j];
                    }
                    else if(e[i][k]+e[k][j]==e[i][j]&&i!=j&&j!=k&&k!=i)
                    {
                        cnt[i][j]+=cnt[i][k]*cnt[k][j];
                        //cout<<i<<' '<<j<<' '<<k<<'\n';
                    }
                    //cout<<i<<' '<<j<<' '<<cnt[i][j]<<'\n';
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                //cout<<i<<' '<<j<<' '<<e[i][j]<<' '<<cnt[i][j]<<'\n';
                if(e[i][j]!=INT_MAX&&cnt[i][j]==2)ans++;
            }
        }
        cout<<ans/2<<'\n';
    }
    return 0;
}
