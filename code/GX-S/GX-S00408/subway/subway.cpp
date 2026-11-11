#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q,w[500001],k[501],a[501][500001],t[501][500001],x[10005],y[10005];
    cin>>c>>m>>n>>d>>q;
    for(int v=1;v<=m;v++)cin>>w[v];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
    }
    for(int r=1;r<=q;r++)cin>>x[r]>>y[r];
    for(int r=1;r<=q;r++)
    {
        int min_sum_t=500000,sum_t=0;
        sum_t+=w[x[r]];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k[i];j++)
            {
                if(x[r]==a[i][j])
                {
                    sum_t+=t[i][j];
                    for(int j2=1;j2<=k[i];j2++)
                    {
                        if(j2==j)continue;
                        for(int i2=1;i2<=n;i2++)
                        {
                            if(i2==i)continue;
                            if(a[i2][j]==y[r])
                            {
                                sum_t+=w[y[r]];
                                min_sum_t==min(min_sum_t,sum_t);
                                break;
                            }
                            for(int j3=1;j3<=k[i2];j3++)
                            {
                                if(j3==j2||j3==j1)continue;
                                if(a[i2][j3]==y[r])
                                {
                                    sum_t+=w[y[r]];
                                    min_sum_t==min(min_sum_t,sum_t);
                                    break;
                                }if(a[i2][j3]==a[i][j2])
                                {
                                    sum_t+=t[i][j2]+t[i2][j3];
                                    for(int i3=1;i3<=n;i3++)
                                    {
                                        if(a[i3][j3]==y[r])
                                        {
                                            sum_t+=w[y[r]];
                                            min_sum_t==min(min_sum_t,sum_t);
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }cout<<min_sum_t<<endl;
    }
    return 0;
}
