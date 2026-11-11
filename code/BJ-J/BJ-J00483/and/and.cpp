#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],vis[N],n,m,ans,b,cnt;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=29;~i;i--){
        b=1<<i;
        cnt=0;
        for(int i=1;i<=n;i++){
            if(vis[i])continue;
            if(a[i]&b)cnt++;
        }
        if(cnt>=m){
            ans|=b;
            for(int i=1;i<=n;i++)
                if(!(a[i]&b))vis[i]=1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
//x x xxx