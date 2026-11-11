#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],v[1000005],ans=-1;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],v[i]=1;
    for(int i=30;i>=0;i--){
        int o=0;
        for(int j=1;j<=n;j++){
            if(((a[j]>>i)&1)&&v[j]){
                o++;
            }
        }
        if(o>=m){
            for(int j=1;j<=n;j++){
                if(!((a[j]>>i)&1)&&v[j])v[j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(v[i]){
            if(ans==-1)ans=a[i];
            else ans&=a[i];
        }
    }
    cout<<ans;
    return 0;
}
