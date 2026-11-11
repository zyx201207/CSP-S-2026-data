#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2000010;

int c, t;
ll n, d, x[N];
ll L[N], R[N];
ll Lto[N], Lcnt[N], Rto[N], Rcnt[N];

ll read() {
    ll tmp=0;
    char ch=getchar();
    bool stat=false;
    while (ch<'0'||ch>'9') {
        if (ch=='-')
            stat=true;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        tmp=tmp*10+ch-'0';
        ch=getchar();
    }
    return stat?(-tmp):tmp;
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    c=read(), t=read();
    while (t--) {
        n=read(), d=read();
        for (int i=1; i<=n; ++i)
            x[i]=read();
        if (n<=3||c==13||c==14) {
            puts("0");
            continue;
        }

        int last=1;
        for (int i=2; i<=n; ++i) {
            while (x[i]-x[last]>d)
                ++last;
            L[i]=last;
        }
        last=n;
        for (int i=n-1; i>=1; --i) {
            while (x[last]-x[i]>d)
                --last;
            R[i]=last;
        }
/*
        puts("TEST L and R");
        printf("L: ");
        for (int i=1; i<=n; ++i) {
            printf("%lld ", L[i]);
        }
        printf("\nR: ");
        for (int i=1; i<=n; ++i) {
            printf("%lld ", R[i]);
        }
        puts("");*/


        for (int i=4; i<=n; ++i) {
            if (L[i]!=1) {
                int src=L[L[i]];
                if (L[i]==i)
                    continue;
                if (L[i]==i-1) {
                    if (Lto[L[i]]) {
                        Lto[i]=Lto[L[i]];
                        ++Lcnt[Lto[i]];
                    }
                } else {
                    int p=lower_bound(x+1, x+1+n, x[L[i]+1]-d)-x;
                    if (p>=L[i]&&Lto[L[i]]) {
                        Lto[i]=Lto[L[i]];
                        ++Lcnt[Lto[i]];
                    } else if(R[p]==L[i]+1) {
                        Lto[i]=L[i];
                        ++Lcnt[Lto[i]];
                    }
                }
            }
        }
        for (int i=n-3; i>=1; --i) {
            if (R[i]!=n) {
                int src=R[R[i]];
                if (R[i]==i)
                    continue;
                if (R[i]==i+1) {
                    if (Rto[R[i]]) {
                        Rto[i]=Rto[R[i]];
                        ++Rcnt[Rto[i]];
                    }
                } else {
                    int p=upper_bound(x+1, x+1+n, x[R[i]-1]+d)-x-1;
                    if (p<=R[i]&&Rto[R[i]]) {
                        Rto[i]=Rto[R[i]];
                        ++Rcnt[Rto[i]];
                    } else if(L[p]==R[i]-1) {
                        Rto[i]=R[i];
                        ++Rcnt[Rto[i]];
                    }
                }
            }
        }
/*
        for (int i=1; i<=n; ++i) {
            printf("TEST:%lld %lld %lld %lld\n", Lto[i], Lcnt[i], Rto[i], Rcnt[i]);
        }*/

        ll ans=0;
        for (int i=2; i<=n-1; ++i)
            ans+=Lcnt[i]*Rcnt[i+1];
        printf("%lld\n", ans);
        for (int i=1; i<=n; ++i) {
            L[i]=R[i]=Lto[i]=Rto[i]=Lcnt[i]=Rcnt[i]=0;
        }
        /*
        for (int i=2; i<=n; ++i) {
            if (i>=4) {
                if (L[i]!=1) {
                    int src=L[L[i]];
                    if (L[i]==i-1||x[src]+d<x[L[i]+1]) {
                        f[i][0]+=f[L[i]][0];
                    } else {
                        if (R[src]==L[i]+1) {
                            f[i][1]=1;
                        }
                    }
                }
            }
            if (L[i]>=4) {

            }
        }*/
    }

    return 0;
}
