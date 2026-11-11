#include<bits/stdc++.h>
using namespace std;
int a[200010];
bool vis[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) vis[i]=1;
    int ans=0;
    for(int i=29;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(vis[j]&&(a[j]&(1<<i))) cnt++;
        }
        if(cnt>=m){
            ans+=(1<<i);
            for(int j=1;j<=n;j++){
                if(!(a[j]&(1<<i))) vis[j]=0;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}