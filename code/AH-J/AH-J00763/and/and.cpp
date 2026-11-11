#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],vis[1000005],k,ans=(1LL<<31)-1;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    k=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=31;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(!vis[j]){
                cnt+=!(bool)(a[j]&(1<<i));
                //cout<<j<<" ";
            }
        }
        //cout<<endl;
        if(k-cnt>=m){
            k-=cnt;
            for(int j=1;j<=n;j++){
                if(!vis[j]&&!(bool)(a[j]&(1<<i))){
                    vis[j]=1;
                }
            }
        }
    }
    //cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            //cout<<ans<<" "<<a[i]<<endl;
            ans=ans&a[i];
        }
    }
    cout<<ans;
    return 0;
}
