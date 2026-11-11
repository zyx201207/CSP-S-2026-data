#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,k) for(ll i=j;i<=k;i++)
#define pll pair<ll,ll>
const int N=2e5+12;
bool c(pll a,pll b){
    if(a.first!=b.first) return a.first>b.first;
    return a.second>b.second;
}
bool c2(pll a,pll b){
    if(a.second!=b.second) return a.second>b.second;

}
ll nu1(ll a){
    ll n=pow(2,int(log2(a))+1);
    ll ans=0;
    for(ll i=n;i>=1;i/=2){
        if(a>=i){
            a-=i;
            ans++;
        }
    }
    return ans;
}
void solve(){
    pll p[N];
    ll n,m;
    cin>>n>>m;
    f(i,1,n){
        cin>>p[i].second;
        p[i].first=nu1(p[i].second);
    }
    //ll ans=0,x,y;
    /*f(i,1,n){
        f(j,i+1,n){
            ll as=p[i].second&p[j].second;
            if(as>ans) x=p[i].second,y=p[j].second;
            ans=max(ans,as);
        }
    }*/
    sort(p+1,p+n+1,c);

    sort(p+1,p+m+1,c2);
    ll ans=p[1].second;
    f(i,1,m){
        if(nu1(ans&p[i].second)==1){
            m++;
            continue;
        }
        if((ans&p[i].second)==0){
            m++;
            continue;
        }
        ans&=p[i].second;
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    while(t--){
        solve();
    }
    return 0;
}
