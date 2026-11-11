#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
bool vis[N];
int cnt;
int ans=((1 << 30)-1);
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    for(int j=29;~j;j--) {
        cnt=0;
        for(int i=1;i<=n;i++) {
            if(vis[i]) continue;
            if((a[i] >> j) & 1) cnt++;
        }
        if(cnt >= m) {
            for(int i=1;i<=n;i++) {
                if(vis[i]) continue;
                if(!((a[i] >> j) & 1)) vis[i]=true;
            }
            if(cnt==m) break;
        }
    }
    cnt=0;
    for(int i=1;i<=n;i++) {
        if(cnt==m) break;
        if(!vis[i]) {
            ans &= a[i];
            cnt++;
        }
    }
    printf("%d",ans);
    return 0;
}
