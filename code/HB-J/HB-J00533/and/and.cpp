#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans;
bool f[200005],a[200005][35];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        ll x,cnt=0;
        cin>>x;
        while(x>0){
            if(x&1){
                a[i][cnt]=1;
            }
            x>>=1;
            cnt++;
        }
    }
    for(ll j=30;j>=0;j--){
        ll sum=0;
        for(ll i=1;i<=n;i++){
            if(f[i]) continue;
            sum+=a[i][j];
        }
        if(sum>=m){
            for(ll i=1;i<=n;i++){
                if(f[i]==0&&a[i][j]==0){
                    f[i]=1;
                }
            }
            ans+=pow(2,j);
        }
    }
    cout<<ans;
    return 0;
}
