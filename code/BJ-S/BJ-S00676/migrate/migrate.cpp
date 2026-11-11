#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e6 + 5;
int T,n;
ll d;
int pre[MAXN],nxt[MAXN];
int mxp[MAXN],mnn[MAXN];
int L[MAXN],R[MAXN];
ll a[MAXN];

int main(){
    #ifndef kevin
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    #endif
    scanf("%*d%d",&T);
    while (T --){
        scanf("%d%lld",&n,&d);
        for (int i = 1;i <= n;i ++)scanf("%lld",a + i);
        int j = 1;
        for (int i = 1;i <= n;i ++){
            while (a[i] - a[j] > d)j ++;
            if (i == j)pre[i] = -1;
            else pre[i] = j;
        }
        j = n;
        for (int i = n;i >= 1;i --){
            while (a[j] - a[i] > d)j --;
            if (i == j)nxt[i] = -1;
            else nxt[i] = j;
        }
        for (int i = 0;i <= n + 1;i ++)mxp[i] = -1,mnn[i] = n + 1;
        for (int i = 1;i <= n;i ++)if (pre[i] != -1)mxp[pre[i]] = i;
        for (int i = n;i >= 1;i --)if (nxt[i] != -1)mnn[nxt[i]] = i;
        for (int i = 1;i <= n;i ++)mxp[i] = max(mxp[i],mxp[i - 1]);
        for (int i = n;i >= 1;i --)mnn[i] = min(mnn[i],mnn[i + 1]);
        // for (int i = 1;i <= n;i ++)printf("mxp %d = %d\n",i,mxp[i]);
        // printf("\n");
        for (int i = 1;i <= n;i ++){
            if (pre[i] == -1 || nxt[pre[i]] != i)L[i] = 1;
            else{
                L[i] = L[pre[i]] + 1;
                int l = max(pre[i] + 1,mnn[i]);
                int r = min(mnn[i + 1] - 1,i - 1);
                if (r >= l)L[i] += r - l + 1;
            }
        }
        for (int i = n;i >= 1;i --){
            if (nxt[i] == -1 || pre[nxt[i]] != i)R[i] = 1;
            else{
                R[i] = R[nxt[i]] + 1;
                int l = max(i + 1,mxp[i - 1] + 1);
                int r = min(nxt[i] - 1,mxp[i]);
                if (r >= l)R[i] += r - l + 1;
            }
        }
        ll ans = 0;
        for (int i = 1;i < n;i ++){
            // printf("(%d,%d) %d %d %d\n",i,i + 1,pre[i] == -1,nxt[pre[i]] != i + 1,nxt[i + 1] == -1);
            ll u = 0;
            if (pre[i] != -1){
                int l = max(pre[i] + 1,mnn[i + 1]);
                int r = min(mnn[i + 2] - 1,i - 1);
                // printf("[%d,%d]\n",l,r);
                if (r >= l)u += r - l + 1;
                if (nxt[pre[i]] == i + 1)u += L[pre[i]];
            }
            ll v = 0;
            if (nxt[i + 1] != -1){
                int l = max(i + 2,mxp[i - 1] + 1);
                int r = min(nxt[i + 1] - 1,mxp[i]);
                // printf("[%d,%d]\n",l,r);
                if (r >= l)v += r - l + 1;
                if (pre[nxt[i + 1]] == i)v += R[nxt[i + 1]];
            }
            ans += u * v;
            // printf("i %d u %lld v %lld\n",i,u,v);
        }
        printf("%lld\n",ans);
    }
    return 0;
}