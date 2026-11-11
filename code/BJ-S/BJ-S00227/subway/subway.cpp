#include<bits/stdc++.h>
using namespace std;
const long long M=510;
const long long MM=5*1e5+20;
long long w[MM],ans[M][M],k[M][MM];
bool flg[M][M];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    memset(k,0x3f,sizeof(k));
    memset(ans,0x3f,sizeof(ans));
    for(long long i=1;i<=n;i++)
    {
        long long x;
        cin>>x;
        for(long long j=1;j<=x;j++)
        {
            long long y,t;
            cin>>y>>t;
            k[i][y]=t;
        }
    }
    for(long long i=1;i<=n;i++)
    {
        for(long long j=i+1;j<=n;j++)
        {
            for(long long r=1;r<=m;r++)
            {
                if(k[i][r]!=0&&k[j][r]!=0)
                {
                    if(ans[i][j]>k[i][r]+k[j][r])
                    {
                        ans[i][j]=k[i][r]+k[j][r];
                        ans[j][i]=k[i][r]+k[j][r];
                        flg[i][j]=1;
                        flg[j][i]=1;
                    }

                }
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int r=1;r<=n;r++)
            {
                if(i==r)
                {
                    continue;
                }
                if(flg[i][r]==0)
                {
                    continue;
                }
                if(k[i][j]>k[r][j]+ans[i][r])
                {
                    k[i][j]=k[r][j]+ans[i][r];
                }
                if(k[r][j]>k[i][j]+ans[i][r])
                {
                    k[r][j]=k[i][j]+ans[i][r];
                }

            }
        }
    }


    while(q--)
    {
        long long x,y,ANS=INT_MAX;
        cin>>x>>y;
        for(long long i=1;i<=n;i++)
        {
            long long anss=0;
            if(k[i][x]==0)
            {
                continue;
            }
            else
            {
                if(k[i][y]!=0)
                {
                    anss=k[i][y]+k[i][x];
                }
                else
                {
                    continue;
                }
            }
            ANS=min(ANS,anss);
        }
        cout<<ANS+w[x]+w[y]<<endl;
    }
    return 0;
}
