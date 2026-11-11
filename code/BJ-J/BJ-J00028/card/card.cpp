#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5 * 1e5 + 1;
const int MAXM = 3 * 1e5 + 1;

int n, m, a[MAXN], sum[MAXM];

void slove(int r)
{
    int G[MAXN];
    int pre[MAXM];
    memset(G,0,sizeof(G));
    memset(pre,0,sizeof(pre));

    for(int i = r;i <= n;i++)
    {
        if(pre[a[i]] == 0) pre[a[i]] = i,G[i] = i + 1;
        else
        {
            G[pre[a[i]]] = i + 1;
            //for(int j = G[pre[a[i]]] + 1;j <= i;j++) if (pre[a[j]] == j) pre[a[j]] = 0;
        }
        printf("i:%d G:%d\n",i,G[i]);
    }

    //for(int i = r;i != n + 1;i = G[i]) sum[a[i]]++;


    return;
}

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++) scanf("%d",&a[i]);

    for(int i = 1;i <= n;i++) slove(i);

    for(int i = 1;i <= m;i++) printf("%d ",sum[i]);

    return 0;
}
