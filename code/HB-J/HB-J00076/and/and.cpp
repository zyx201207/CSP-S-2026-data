#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, res;
int book[200005];
int a[200005];
void dfs(int x, int now, int step){
    if(book[x])
        return;
    if(step==m){
        res=max(now, res);
        return;
    }
    book[x]=1;
    for(int i=1;i<=n;i++)
        if(i!=x)
            dfs(i,now & a[i], step+1);
    book[x]=0;
    return;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
       cin>>a[i];
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
        return 0;
    }
    if(m==2){
        int ans=0;
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                ans=max(a[i]&a[j],ans);
        cout<<ans;
        return 0;
    }
    if(m==n){
        int ans=1;
        for(int i=1;i<=n;i++)
            ans&=a[i];
        cout<<ans;
        return 0;
    }
    if(n<=20){
        for(int i=1;i<=n;i++)
            dfs(i,a[i],1);
        cout<<res;
        return 0;
    }
    return 0;
}
