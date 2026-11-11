#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,t[200005][40],ans[40],a[200005],vis[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        vector<ll> cnt;
        ll x=a[i];
        while(x){
            cnt.push_back(x%2);
            x/=2;
        }
        ll l=0;
        for(int j=cnt.size()-1;j>=0;j--){
            t[i][j]=cnt[j];
        }
    }
    for(int i=0;i<=n;i++) vis[i]=1;
    for(int i=31;i>=0;i--){
        ll k=0;
        for(int j=1;j<=n;j++){
               // cout<<t[j][i]<<" ";
            if(t[j][i]&&vis[j]) k++;
        }
       // cout<<endl;
        if(k>=m){
            for(int j=1;j<=n;j++){
                if(!t[j][i]) vis[j]=0;
            }
            ans[i]=1;
        }
    }
    ll res=0,x=1;
    for(int i=0;i<=31;i++){
        res+=x*ans[i];
        x*=2;
    }
    cout<<res;
    return 0;
}
