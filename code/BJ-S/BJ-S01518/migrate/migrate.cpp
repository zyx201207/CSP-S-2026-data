#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=2e6+5;
ll x[N],to[N];
ll f[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,_;
    cin>>c>>_;
    while(_--){
        ll n,d;
        cin>>n>>d;
        for (int i=1;i<=n;i++){
            cin>>x[i];
            to[i]=0;
        }
        if(c==11||c==12){
            ll cha=x[2]-x[1];
            ll xx=d/cha;
            if(xx<=1){
                cout<<"0\n";
            }else{
                // cout<<"***"<<xx<<"\n";
                ll ppp=xx*2-1;
                cout<<max(n-ppp,0ll)<<"\n";
            }
        }else{
            ll r=1;
            for (int i=1;i<=n;i++){
                while(r<=n&&x[r]-x[i]<=d){
                    r++;
                }
                to[i]=r-1;
                // cout<<to[i]<<" \n"[i==n];
            }
            ll ans=0;
            vector<ll> v;
            for (int i=1;i<=n;i++){
                for (int j=i+1;j<=n;j++){
                    f[j]=0;
                }
                v.clear();
                ll x=i;
                while(to[x]!=x){
                    v.push_back(to[x]);
                    x=to[x];
                }
                if(v.size()<=1){
                    continue;
                }
                for (int j=i+1;j<=v[0];j++){
                    f[j]=1;
                    if(to[j]>v[0]){
                        f[v[0]+1]++;
                        f[to[j]+1]--;
                    }
                }
                for (int j=v[0]+2;j<=v[1]+1;j++){
                    f[j]+=f[j-1];
                }
                ll len=v.size();
                for (int j=1;j<len-1;j++){
                    for (int k=v[j-1]+1;k<=v[j];k++){
                        if(to[k]>v[j]){
                            f[v[j]+1]+=f[k];
                            // cout<<k<<" "<<to[k]<<"\n";
                            f[to[k]+1]-=f[k];
                        }
                    }
                    // for (int k=i+1;k<=n;k++){
                    //     cout<<f[k]<<" \n"[k==n];
                    // }
                    for (int k=v[j]+2;k<=v[j+1]+1;k++){
                        f[k]+=f[k-1];
                    }
                    // for (int k=i+1;k<=n;k++){
                    //     cout<<f[k]<<" \n"[k==n];
                    // }
                }
                for (int j=i+1;j<=n;j++){
                    // cout<<f[j]<<" \n"[j==n];
                    ans+=(f[j]==2);
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}