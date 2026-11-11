#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,c,ans;
ll m,a[500005],ch[500005],chk[500005];
bool f=1;
void dfs(int u) {
    if(u>n) {
        for(int i=1;i<=c;i++)
            chk[i]=ch[i];
        sort(chk+1,chk+c+1);
        // for(int i=1;i<=c;i++)
        //     printf("%lld ",chk[i]);
        // puts("");
        ll nd=0;
        for(int i=2;i<=c;i++) {
            nd+=(i-1)*(ch[i]-ch[i-1]);
            if(nd>m)
                return ;
        }
        ans=max(ans,c);
        return ;
    }
    dfs(n+1);
    for(int i=u;i<n;i++) {
        ch[++c]=a[i];
        dfs(i+1);
        c--;
    }
}
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) {
        if(i>2 && a[i]-a[i-1]!=a[2]-a[1])
            f=0;
        scanf("%lld",&a[i]);
    }
    if(f) {
        ll nd=0;
        for(int i=2;i<=n;i++) {
            nd+=(i-1)*(ch[i]-ch[i-1]);
            if(nd>m) {
                ans=i-1;
                break;
            }
        }
    }
    else {
        dfs(1);
    }
    printf("%d\n",ans);
    return 0;
}