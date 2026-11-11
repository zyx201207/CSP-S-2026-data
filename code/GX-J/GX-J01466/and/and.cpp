#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
int a[200000+15];
long long dfs(int cnt,int i,long long ans) {
    if (i>n)return ans;
    //if (cnt==m)return ans;
    if ((n-i)<=(m-cnt))return dfs(cnt+1,i+1,ans&a[i]);
    return max(dfs(cnt+1,i+1,ans&a[i]),dfs(cnt,i+1,ans));
}
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    long long ans=-100000010;
    for (int i=1;i<=n;i++) {
        long long t=dfs(1,i+1,a[i]);
        if (t>ans)ans=t;
    }
    printf("%lld",ans);
    return 0;
}
