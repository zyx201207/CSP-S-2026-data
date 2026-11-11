#include <iostream>
#include <cstring>
#include <string>
using namespace std;
long long w[500005];
long long xianzhan[50005];
long long a1[500][50000];
long long a2[500][50000];
long long t1[500][50000];
long long t2[500][50000];
long long ys[50005];
bool guo[505];
long long c, n, m, d, q;
void sou(int x, int y)
{
    for(long long j=1; j<=n; j++)
    {
        if(a1[j][y]!=0&&j!=x&&guo[j]==0)
        {
            guo[j]=1;
            for(long long z=1; z<=xianzhan[j]; z++)
            {
                if(ys[a2[j][z]]!=0)
                    ys[a2[j][z]]=min(ys[a2[j][z]],(ys[y]+t2[j][y]+t1[j][z]));
                else
                    ys[a2[j][z]]=ys[y]+t2[j][y]+t1[j][z];
                sou(j,z);
            }
        }
    }
    return ;
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    for(long long  i=1; i<=m; i++)
    {
        cin >> w[i];
    }
    for(long long  i=1; i<=n; i++)
    {
        cin >> xianzhan[i];
        for(long long  j=1; j<=xianzhan[i]; j++)
        {
            long long  hao;
            cin >>hao;
            a1[i][hao]=1;

            a2[i][j]=hao;
            long long  shi;
            cin >> shi;
            t1[i][j]=shi;
            t2[i][hao]=shi;
        }
    }


    for(long long  i=1; i<=q; i++)
    {
        memset(ys, 0, sizeof(ys));
        memset(guo, 0, sizeof(guo));
        long long  m1, m2;
        cin >> m1 >> m2;
        ys[m1]=w[m1];
        long long  dzhan=m1;
        sou(0, dzhan);
        cout << ys[m2]+w[m2] << endl;

    }

    return 0;
}
