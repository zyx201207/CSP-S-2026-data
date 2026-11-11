#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 5015;
int C,T,n,y[maxn];
ll d,x[maxn],ans;
ull sum[maxn][maxn];
void add(int i,int l,int r,ull c)
{
    sum[i][l]+=c;
    sum[i][r+1]-=c;
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--)
    {
        ans = 0;
        scanf("%d%lld",&n,&d);
        for(int i =1;i<=n;++i)
        {
            scanf("%lld",&x[i]);
        }
        for(int i =1;i<=n+1;++i)
        {
            for(int j =1;j<=n+1;++j)
            {
                sum[i][j] = 0;
            }
            y[i] = i;
        }
        for(int i =1;i<=n;++i)
        {
            sum[i][i+1]+=1;
            for(int j =i+1;j<=n+1;++j)
            {
                if(x[j]-x[i]>d||j==n+1)
                {
                    y[i] = j-1;
                    sum[i][j]-=1;
                    break;
                }
            }
        }
        int r1,r3;
        for(int i =1;i<=n;++i)
        {
            r1 = y[i];
            for(int r2 =i+1;r2<=n;++r2)
            {
                sum[i][r2]+=sum[i][r2-1];
                r3=y[r2];
                add(i,r1+1,r3,sum[i][r2]);
                if(r2==r1)
                {
                    r1 = y[r1];
                }
                if(r2>r1)
                    break;
            }
        }
        /*
        for(int i =1;i<=n;++i)
        {
            for(int j =2;j<=n;++j)
                sum[i][j]+=sum[i][j-1];
        }
        */
        for(int i =1;i<=n;++i)
            for(int j=i+1;j<=n;++j)
            {
                //printf("sum[%d][%d]=%d\n",i,j,sum[i][j]);
                if(sum[i][j]==(ull)2)
                {
                    ++ans;
                }
            }
        printf("%d\n",ans);
    }
    return 0;
}
