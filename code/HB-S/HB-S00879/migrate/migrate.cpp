#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000005;
ll n=0;
ll c=0;
ll t=0;
ll d=0;
ll a[N];
ll f[1005][1005];
ll dig[1005][1005];

void clr(){
    for(ll ii=0;ii<N;ii++){
        a[ii]=0;
    }
}

ll solve(){
    for(ll k=1;k<n;k++){
        for(ll l=0;l+k<n;l++){
            ll r=l+k;
            if(a[r]-a[l]<=d){
                f[l][r]=1;
                f[r][l]=1;
            }
            else{
                for(ll i=l;i<r;i++){
                    if(f[l][i]&& f[i][r]){
                        f[l][r]=f[l][i]+f[i][r];
                    }
                }
            }
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<i;j++){
            for(ll k=0;k<n;k++){
                if(f[i][k]+f[k][j]=f[i][j]){
                    dig[i][j]++;
                }
            }
        }
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<i;j++){
            if(dig[i][j]){
                ans++;
            }
        }
    }
    return ans;
}

ll trick_a(){
    ll dif=a[1]-a[0];
    if(2*d <= dif < 3*d){
        return n-2;
    }
    else return 0;
}

ll trick_b(){
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(ll ii=0;ii<t;ii++){
        cin>>n>>d;
        clr();
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        if(c==11 || c==12){
            cout << trick_a();
        }
        if(c==13 || c==14){
            cout << trick_b();
        }
        else cout << solve();
        cout << "\n";
    }
    return 0;
}
