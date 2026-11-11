#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q, ans;
int fa[1000005],w[1000005];
struct h{
    int sum;
    int a[505];
}f[50005];
struct line{
    int k;
    int a[500005], t[500005];
}l[505];
struct edge{
    int k, v[505], we[505];
}uu[505];

bool vis[505];
void bfs(int s, int e, int dp){
    if(s == e){
        ans = min(ans, dp);
        return ;
    }

    for(int i=1; i<=uu[s].k; i++){
        vis[uu[s].v[i]] = true;
        bfs(uu[s].v[i], e, dp+uu[s].we[i]);
    }
    return ;
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1; i<=m; i++){
        cin >> w[i];
    }
    for(int i=1; i<=n; i++){
        cin >> l[i].k;
        for(int j=1; j<=l[i].k; j++){
            cin >> l[i].a[j] >> l[i].t[j];
            f[l[i].a[j]].sum++;
            int x = f[l[i].a[j]].sum;
            f[l[i].a[j]].a[x] = i;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            for(int i1=1; i1<=l[i].k; i1++){
                bool flag1 = 0;
                for(int i2=1; i2<=l[j].k; i2++){
                    if(l[i].a[i1] == l[j].a[i2]){
                        uu[i].k++;
                        uu[i].v[uu[i].k] = j;
                        uu[i].we[uu[i].k] = l[i].t[i1]+l[j].t[i2];
                        flag1 = 1;
                        break;
                    }
                }
                if(flag1){
                    break;
                }
            }
        }
    }
    while(q--){
        ans = 0x3f3f3f3f;
        for(int i=1; i<=500; i++){
            vis[i] = false;
        }
        int st = 0, ed = 0;
        cin >> st >> ed;
        int ans2 = 0x3f3f3f3f;
        for(int p=1; p<=f[st].sum; p++){
            fa[st] = f[st].a[p];
            for(int q=1; q<=f[ed].sum; q++){
                fa[ed] = f[ed].a[q];

                bfs(fa[st], fa[ed], 0);
                int t1 = 0, t2 = 0;
                for(int i=1; i<=l[fa[st]].k; i++){
                    if(l[fa[st]].a[i] == st){
                        t1 = l[fa[st]].t[i];
                    }
                }
                for(int i=1; i<=l[fa[ed]].k; i++){
                    if(l[fa[ed]].a[i] == ed){
                        t2 = l[fa[ed]].t[i];
                    }
                }
                ans2 = min(ans2, w[st]+w[ed]+t1+t2+ ans);
            }
        }
        cout << ans2 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
 }
