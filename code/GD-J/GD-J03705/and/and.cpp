#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
bool vis[N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],vis[i]=1;

    for(int x=30;x>=0;x--){
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(vis[i]&&((a[i]>>x)&1)) cnt++;
        
        if(cnt>=m){
            ans^=(1<<x);
            for(int i=1;i<=n;i++)
                if(!((a[i]>>x)&1)) vis[i]=0; 
        }
    }
    cout<<ans;
    return 0;
}