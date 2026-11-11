#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m;
ll a[N];
ll c[N];
ll d[N];

bool cmp(ll q,ll w){
    return q<w;
}
int main(){
    // 注意修改宏
	// 注意加freopen
	
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    c[1]=a[1];
    d[1]=0;
    for(int i=2;i<=n;i++){
        c[i]=a[i]-a[i-1];
        d[i]=d[i-1]+(i-1)*c[i];
    }
    ll l=1;
    ll ans=1;
    for(ll r=1;r<=n;r++){
        ll cnt=0;
        cnt=d[r]-(l-1)*(a[r]-a[l])-d[l];
        if(cnt<=m){
            ans=max(ans,(r-l)+1);
        }
        else{
            while(cnt>m){
                l++;
                cnt=d[r]-(l-1)*(a[r]-a[l])-d[l];
            }
        }
    }
    cout<<ans;
    return 0;
}
