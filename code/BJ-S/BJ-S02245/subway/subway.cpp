#include <bits/stdc++.h>
using namespace std;
int w[500005],ans[100005];
int x[100005],y[100005];
int fa[500005];
int fnd(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=fnd(fa[x]);
}
void unite(int x,int y)
{
    int fx=fnd(x),fy=fnd(y);
    if(fx!=fy) fa[fx]=fy;
}
struct way{
    int a,t,kk;
};
way wy[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,k;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> w[i];
    }
    for(int i = 1;i <= m;i++) fa[i]=i;
    for(int i = 1;i <= n;i++){
        cin >> k;
        for(int j = 1;j <= k;j++){
            cin >> wy[j].a >> wy[j].t;
            wy[j].kk=k;
        }
    }
    for(int i = 1;i <= q;i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 1;i <= q;i++){
        int anstmp;
        int nowi=x[i];
        for(int ii=1;ii <= n;ii++){
            for(int jj=1;jj<= k;jj++){
                if(wy[jj].kk==ii) anstmp+=wy[jj].t;
                if(anstmp>INT_MAX-5e5) anstmp=0;
            }
        }
        ans[i]=anstmp;
    }
    for(int i = 1;i <= q;i++){
        cout << ans[i] << endl;
    }
    return 0;
}
