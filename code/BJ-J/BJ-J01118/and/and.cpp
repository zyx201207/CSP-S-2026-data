#include <bits/stdc++.h>
using namespace std;

long long n,m,ans=-1000000000,a[200020],vis[200020];
void dfs(long long dian,long long sum,long long cnt){
    if (cnt>m){
        return;
    }
    if (cnt==m){
        ans=max(ans,sum);
    }
    vis[dian]=1;
    for (long long i=1;i<=n;i++){
        if (vis[i]==0){
            vis[i]=1;
            dfs(i,sum&a[i],cnt+1);
            vis[i]=0;
        }
    }
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin >> n >> m;
    for (long long i=1;i<=n;i++){
        cin >> a[i];
    }
    if (m==1){
        for (long long i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        cout << ans;
        return 0;
    }
    else if (m==n){
        long long t=a[1];
        for (long long i=2;i<=n;i++){
            t=t&a[i];
        }
        cout << t;
        return 0;
    }
    else{
        for (long long i=1;i<=n;i++){
            memset(vis,0,sizeof(vis));
            dfs(i,a[i],1);
        }
    }
    cout << ans;
	return 0;
}