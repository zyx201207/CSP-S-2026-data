#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e6+10;
ll n,d;
ll a[N],dis[N],f[N];
map<int,ll>mp;
int check(){
    if(n<=300)return 0;
    ll d1=a[2]-a[1];
    for(int i=3;i<=n;i++)if(a[i]-a[i-1]!=d1)return 0;
    return 1;
}
void run(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(check()){
        ll d1=a[2]-a[1];
        ll k=d/d1;
        if(k<=1)cout<<0<<'\n';
        else cout<<max(0ll,n-2*k+1)<<'\n';
        return;
    }
    int ans=0;
    for(int l=1;l<=n;l++){
        for(int i=1;i<=n;i++)dis[i]=1e9,f[i]=0;
        dis[l]=0,f[l]=1;
        mp.clear();
        int mn=l;mp[1]=1;
        // cout<<l<<":\n";
        for(int i=l+1;i<=n;i++){
            while(a[i]-a[mn]>d){
                mp[dis[mn]+1]-=f[mn];
                if(mp[dis[mn]+1]==0)mp.erase(mp.find(dis[mn]+1));
                mn++;
            }
            if(mn==i)break;
            dis[i]=(*mp.begin()).first;
            f[i]=(*mp.begin()).second;
            // cout<<i<<' '<<mn<<' ' <<dis[i]<<' '<<f[i]<<endl;
            mp[dis[i]+1]+=f[i];
        }
        for(int i=l;i<=n;i++){
            // cout<<f[i]<<' '<<dis[i]<<'\n';
            ans+=(f[i]==2);
            // cout<<l<<' '<<i<<' '<<f[i]<<endl;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--)run();
    return 0;
}
//1.433kb