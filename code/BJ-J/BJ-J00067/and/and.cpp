#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+10;
int n,m,a[N],st[N][35],vis[N],ans=0;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        int x=a[i],j=1;
        while(x){
            if(x&1){
                st[i][j]=1;
            }
            x>>=1; j++;
        }
    }
    for(int j=30;j>=1;--j){
        ans<<=1;
        int cnt=0;
        for(int i=1;i<=n;++i){
            if(!vis[i]&&st[i][j])cnt++;
        }
        if(cnt>=m){
            for(int i=1;i<=n;++i){
                if(!st[i][j]) vis[i]=1;
            }
            ans+=1;
        }
    }
    cout<<ans;
    return 0;
}
