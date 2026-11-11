#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[200005];
int ans=0;
void dfs(int cur,int cnt,int vul) {
    if(cnt==0)vul=a[cur];
    if(cnt==m) {
        ans=max(ans,vul);
        return ;
    }
    if(vul<ans)return;

    if(cur>n)return;
    dfs(cur+1,cnt,vul);
    dfs(cur+1,cnt+1,vul&a[cur]);
}

int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    dfs(1,0,0);
    cout<<ans;

}
