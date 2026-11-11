#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
bool vis[200005];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vis[i]=1;
    }
    int ans=0;
    for(int i=31;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++) if(((a[j]>>i)&1)&&vis[j]) cnt++;
        if(cnt>=m){
            ans+=(1<<i);
            for(int j=1;j<=n;j++) if(!((a[j]>>i)&1)) vis[j]=0;
        }
    }
    cout<<ans;
}
