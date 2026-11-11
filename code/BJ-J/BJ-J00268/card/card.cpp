#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N], b[N], ans[N], c[N], cnt[N];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m, cnt2=0;
    scanf("%d%d", &n, &m);
    for(int i = 1;i<=n&&scanf("%d", a+i);i++);
    for(int i = 1;i<=n;i++) {
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        memset(cnt, 0, sizeof(cnt));
        cnt2=0;
        for(int j = i;j<=n;j++) {
            if(cnt[a[j]]>=1)
                for(int k = c[a[j]];k<=cnt2;k++)
                    cnt[b[k]]--, c[b[k]]=0, b[k]=0;
            b[++cnt2]=a[j];
            cnt[a[j]]++;
            c[a[j]]=cnt2;
        }
        for(int j = 1;j<=cnt2;j++)
            ans[b[j]]++;
    }
    for(int i = 1;i<=m;i++)
        printf("%d ", ans[i]);
    return 0;
}
//T4难成啥了
/*
预估100+68+35+48=251?!
不可能
T3全是部分分
upd 11:31
预估100+68+45+48=261?!
upd 11:34
预估100+68+50+48=266?!
upd 11:51
预估100+68+60+48=276?!
疑似知道T3正解，但是不会写
*/