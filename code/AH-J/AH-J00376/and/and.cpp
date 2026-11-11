#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
ll n,m;
ll a[N],vis[N];
ll ans=1;
void dfs(ll x,ll sum,ll p){
    if(x>m){
        ans=max(ans,sum);
        return ;
    }
    for(ll i=1+p;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(x+1,sum&a[i],i);
            vis[i]=0;
        }
    }
    return ;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    ll s1=0,s2=0,s3=0,s4=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        s1+=a[i]==1;
        s2+=a[i]==2;
        s3+=a[i]==3;
        s4+=a[i]==4;
    }
    sort(a+1,a+1+n);
    if(m==1){
        cout<<a[n];
        return 0;
    }
    if(m==n){
        ans=a[1];
        for(ll i=2;i<=n;i++)ans&=a[i];
        cout<<ans;
        return 0;
    }
    if(a[n]<=4){
        if(s4>=m){
            cout<<4;
            return 0;
        }
        else if(s3>=m){
            cout<<3;
            return 0;
        }
        else if(s3+s2>=m){
            cout<<2;
            return 0;
        }
        else if(s3+s1>=m){
            cout<<1;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    ll sj=1;
    bool sf=1;
    for(ll i=n;i>=n-m+1;i--){
        sj*=i;
        if(i==m){
            break;
            sf=0;
        }
    }
    if(sf)for(ll i=1;i<=m;i++)sj/=m;
    if(sj<=100000000LL){
        for(ll i=1;i<=n;i++){
            vis[i]=1;
            dfs(2,a[i],i);
            vis[i]=0;
        }
        cout<<ans;
        return 0;
    }
    ans=a[n];
    for(ll i=n-1;i>=n-m+1;i--)ans&=a[i];
    cout<<ans;
    return 0;
}
