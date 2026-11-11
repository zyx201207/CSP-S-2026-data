#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,a[5001],ans[3001];

int main() {
    freopen ("card.in","r",stdin);
    freopen ("card.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;i++) {
        scanf ("%d",&a[i]);
    }
    for (int i=1;i<=n;i++) {
        int b[5001],c[3001],sum=0;
        memset (b,0,sizeof(b));
        memset (c,0,sizeof(c));
        for (int j=i;j<=n;j++) {
            if (c[a[j]]==0) {
                sum++;
                b[sum]=a[j];
                c[a[j]]=sum;
            }
            else {
                sum=c[a[j]];
                for (int k=1;k<=m;k++) {
                    if (c[k]>sum) {
                        c[k]=0;
                    }
                }
            }
        }
        for (int j=1;j<=sum;j++) {
            ans[b[j]]++;
        }
    }
    for (int i=1;i<=m;i++) {
        printf ("%d ",ans[i]);
    }
    return 0;
}
