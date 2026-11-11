#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
const int N=2e6+5;
int c,t,n;
ll a[N],d;
int num[N];
ll cnt[N],dis[N];
void solve1(){
    while(t--){
        cin>>n>>d;
        rep(i,1,n) cin>>a[i];
        int l=1,r=1;
        while(l<=n){
            while(r<=n&&a[r]<=a[l]+d) r++;
            num[l]=r-1;
            l++;
        }
        // rep(i,1,n) cout<<num[i]<<' ';
        // cout<<'\n';
        int ans=0;
        per(i,n,1){
            rep(j,1,n) cnt[j]=0,dis[j]=n+1;
            cnt[i]=1,dis[i]=0;
            rep(j,i,n){
                rep(k,j+1,num[j]){
                    if(dis[k]>dis[j]+1){
                        dis[k]=dis[j]+1;
                        cnt[k]=cnt[j];
                    }
                    else if(dis[k]==dis[j]+1) cnt[k]+=cnt[j];
                }
            }
            // cout<<i<<' ';
            rep(j,i,n){
                if(cnt[j]==2) ans++;
                // cout<<cnt[j]<<' ';
            }
            // cout<<'\n';
        }
        cout<<ans<<'\n';
    }
}
void solve2(){
    while(t--){
        cin>>n>>d;
        rep(i,1,n) cin>>a[i];
        if(n==1){
            cout<<"0\n";
            continue;
        }
        ll cha=a[2]-a[1];
        if(d<cha*2){
            cout<<"0\n";
            continue;
        }
        d/=cha;
        // ll ans=(n-1)/d;
        // if((n-1)%d>=d-1) ans++;
        // cout<<ans<<'\n';
        cout<<max(0ll,n-2*d+1)<<'\n';
    }
}
void solve3(){
    while(t--){
        cin>>n>>d;
        rep(i,1,n) cin>>a[i];
        int l=1,r=1;
        while(l<=n){
            while(r<=n&&a[r]<=a[l]+d) r++;
            num[l]=r-1;
            l++;
        }
        ll ans=0;
        rep(i,1,n){
            if(num[i]==n||num[i]<=2) continue;
            if(num[num[i]-1]<=num[i]) continue;
            ll tmp=num[num[i]-1]-max(num[i],num[num[i]-2]);
            if(tmp>0) ans+=tmp;
        }
        cout<<ans<<'\n';
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    if(c<=10) solve1();
    else if(c<=12) solve2();
    else if(c<=14) solve3();
    return 0;
}