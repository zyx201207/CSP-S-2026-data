#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N], n, m, ans;
bool vis[N];
void dfs(int step) {
    if(step>m) {
        int tmp=INT_MAX;
        for(int i = 1;i<=n;i++)
            if(vis[i])
                tmp&=a[i];
        ans=max(ans, tmp);
        return ;
    }
    for(int i = 1;i<=n;i++)
        if(!vis[i])
            vis[i]=true, dfs(step+1), vis[i]=false;
}
bool cmp(int a, int b) {
    return (a>>1)>(b>>1);
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    bool flag1=!(n&(n-1)), flag2=true, flag3=true;
    for(int i = 1;i<=n&&scanf("%d", a+i);i++) {
        if(a[i]!=i-1)
            flag1=false;
        if((a[i]+1)&(a[i]))
            flag2=false;
        if(a[i]>=4)
            flag3=false;
    }
    if(m==1) {
        for(int i = 1;i<=n;i++)
            ans=max(ans, a[i]);
    } else if(m==n) {
        ans=INT_MAX;
        for(int i = 1;i<=n;i++)
            ans&=a[i];
    } else if(m==2) {
        for(int i = 1;i<=n;i++)
            for(int j = 1;j<=n;j++)
                if(i!=j)
                    ans=max(ans, a[i]&a[j]);
    } else if(flag1) {
        ans=n-pow(2, int(ceil(log2(m))));
    } else if(flag2) {
        sort(a+1, a+n+1, greater<int>());
        ans=a[m];
    } else if(flag3) {
        int cnt1=0, cnt2=0;
        for(int i = 1;i<=n;i++) {
            if(a[i]&2)
                cnt1++;
            if(a[i]&1)
                cnt2++;
        }
        if(cnt1>=m) {
            ans+=2;
            sort(a+1, a+n+1, cmp);
            int cnt3=0;
            for(int i = 1;i<=cnt1;i++) {
                if(a[i]&1)
                cnt3++;
            }
            if(cnt3>=m)
            ans+=1;
        } else if(cnt2>=m)
            ans++;

    } else
        dfs(1);
    printf("%d", ans);
    return 0;
}
//T3难成啥了