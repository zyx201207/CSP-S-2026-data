#include <bits/stdc++.h>

using namespace std;
long long C,n,m,d,p;
long long k[505];
long long mi[500005];
struct AA{
    long long id,o;
};

vector <AA> dian[500005];
long long me[505][505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> C >> n >> m >> d >> p;
    for(long long i = 1;i <= m;i++) cin >> mi[i];
    memset(me,0x3f,sizeof(me));
    for(long long i = 1;i <= n;i++) me[i][i] = 0;
    for(long long i = 1;i <= n;i++){
        cin >> k[i];
        for(long long j = 1;j <= k[i];j++){
            long long x,y;
            cin >> x >> y;
            if(dian[x].size() > 0){
                for(long long k = 0;k < dian[x].size();k++){
                    me[i][dian[x][k].id] = min(dian[x][k].o+y,me[i][dian[x][k].id]);
                    me[dian[x][k].id][i] = min(dian[x][k].o+y,me[i][dian[x][k].id]);

                }
            }
            dian[x].push_back(AA{i,y});
        }
    }
    for(long long i = 1;i <= n;i++){
        for(long long j = 1;j <= n;j++){
            for(long long k = 1;k <= n;k++){
                me[k][j] = min(me[k][j],me[k][i]+me[i][j]);
                me[j][k] = min(me[j][k],me[j][i]+me[i][k]);
            }

        }
    }

   // cout << "djsfhsd";
    while(p--){
        long long x,y;
        cin >> x >> y;
        long long mn = 0x3f3f3f3f3f3f3f3f;
        for(long long i = 0;i < dian[x].size();i++){
            for(long long j = 0;j < dian[y].size();j++){
                mn = min(me[dian[x][i].id][dian[y][j].id]+dian[x][i].o+dian[y][j].o,mn);

            }

        }
        printf("%lld\n",mn+mi[x]+mi[y]);
    }
    return 0;
}
