#include<bits/stdc++.h>
using namespace std;
struct node {
    long long x, c;
};
const int N=5e5+10;
node a[N];
bool cmp(node a, node b) {
    return a.c<b.c;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    long long m, ans=0;
    bool flag1=true, flag2=true;
    scanf("%d%lld", &n, &m);
    for(int i = 1;i<=n&&scanf("%lld", &a[i].x);i++) {
        if(a[i].x!=i)
            flag1=false;
    }
    int d=a[2].x-a[1].x;
    for(int i = 3;i<=n;i++)
        if(a[i].x-a[i-1].x!=d)
            flag2=false;
    if(flag1) {
        for(int i = 1;i<=n;i++)
            if(i*(i-1)/2<=m)
                ans=i;
    } else if(flag2) {
        for(int i = 1;i<=n;i++)
            if(i*(i-1)/2*d<=m)
                ans=i;
    } else {
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=n;j++) {
                a[j].c=a[i].x-a[j].x;
            }
            long long tmp=0, t=0;
            for(int j = 1;j<=n&&tmp+a[j].c<=m;j++) {
                if(a[j].c>=0)
                    t++, tmp+=a[j].c;
            }
            if(ans<t) {
                ans=t;
            }
        }
    }
    printf("%lld", ans);
    return 0;
}
