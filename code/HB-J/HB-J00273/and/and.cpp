#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[200005];
ll vis[200005];
ll ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];vis[i]=1;
    }
    for(int i=30;i>=0;i--){
        ll cnt=0;
        for(int j=1;j<=n;j++){
            //cout<< (a[j]>>i) <<":" << ((a[j]>>i)&1)<<" ";
            if(((a[j]>>i)&1)&&vis[j]==1){
                cnt++;
            }
        }
        //cout<<cnt<<endl;
        if(cnt>=m){
            ans+=(1<<i);
            //cout<<i<<" ";
            for(int j=1;j<=n;j++){
                if(((a[j]>>i)&1)==0){
                    vis[j]=0;
                }
            }
        }
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
