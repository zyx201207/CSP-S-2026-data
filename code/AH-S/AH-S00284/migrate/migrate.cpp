#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ffor(i,j,k) for(ll i=(j);i<=(k);i++)
#define rfor(i,j,k) for(ll i=(k);i>=(j);i--)
#define vec vector
#define pq priority_queue
#define sta stack
#define pb push_back
#define pob pop_back
#define pof pop_front
#define pob pop_back
#define fi first
#define se second
#define pii pair<ll,ll>
#define debug(x) cout<<"DEBUG:"<<x<<endl;
#define __ " "
#define endl '\n'
#define gc getchar_unlocked
void read(ll &x){
    x=0;int f =1;
    char c = gc();
    while(!isdigit(c)){
        if(c == '-'){
            f = 1;
        }c = gc();
    }
    while(isdigit(c)){
        x = x*10+c-'0';
        c=gc();
    }
    x*=f;
}
int c;
void solve(){
    ll n,d;
    cin>>n>>d;
    vec<ll>a(n+1,0);
    ffor(i,1,n){
        cin>>a[i];
    }
    if(c==11||c == 12){
        ll x = a[2]-a[1];
        if(d<2ll*x){
            cout<<0<<endl;
        }else{
            cout<<max(0ll,n-(1+2*(d/x-1)))<<endl;
        }return;
    }
    ll ans = 0;
    ffor(fi,1,n-1){
        vec<vec<int> >dp(n+1,vec<int>(n+1,0)),sum(n+1,vec<int>(n+1,0));
        dp[0][fi] = 1;
        sum[0][fi] = 1;
        ffor(i,fi+1,n){
            int id = lower_bound(a.begin()+fi,a.begin()+i,a[i]-d)-a.begin();
            sum[0][i] = sum[0][i-1];
            ffor(j,1,n){
                dp[j][i] = sum[j-1][i-1] - sum[j-1][id-1];
                sum[j][i] = sum[j][i-1] + dp[j][i];
            }
            ffor(j,1,n){
                if(dp[j][i]!=0){
                    if(dp[j][i] == 2){
                        ans++;
                        
                    }break;
                }
            }
        }

    }
    cout<<ans<<endl;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T=1;
    cin>>c>>T;
    while(T--){
        solve();
    }
    return 0;
}
