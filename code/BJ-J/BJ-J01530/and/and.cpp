#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,x,s,ans,a[200100],vis[200100][40],p[40],cnt[40],l[200100];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    p[0]=1;
    for(int i=1;i<=35;i++){
        p[i]=p[i-1]*2;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x=upper_bound(p+1,p+40,a[i])-p-1;
        s=max(s,x);
        for(int j=x;j>=0;j--){
            if(a[i]>=p[j]){
                a[i]-=p[j];
                cnt[j]++;
                vis[i][j]=1;
            }
        }
    }
    for(int i=s;i>=0;i--){
        for(int j=1;j<=n;j++){
            if(l[j]==1 and vis[j][i]==1){
                cnt[i]--;
            }
        }
        if(cnt[i]<m){
            continue;
        }
        ans+=p[i];
        for(int j=1;j<=n;j++){
            if(vis[j][i]==0){
                l[j]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
