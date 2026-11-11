#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=-1;
bool d[200005];
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=29;i>=0;i--) {
        int cnt=0;
        for(int j=1;j<=n;j++) {
            if(!d[j] && (a[j]&(1<<i)))
                cnt++;
        }
        if(cnt>=m) {
            for(int j=1;j<=n;j++)
                if(!(a[j]&(1<<i)))
                    d[j]=1;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++) {
        if(!d[i] && cnt<=m) {
            ans&=a[i];
            cnt++;
        }
    }
    printf("%d\n",ans);
    return 0;
}