#include<bits/stdc++.h>
using namespace std;
using ll =long long;
using pii=pair<int,int>;
using pll=pair<long long,long long>;

const double eps =1E-8;
const ll base1=131,base2=13331;
const ll mod1=1E9+7,mod2=1E9+9;
const int N=2E6+20;

vector<ll> a(N);
ll ans,number;
void dfs(ll c,ll r,ll o,ll t) {
    if(o==r) {
        if(ans<c) return;
        if(ans==c) number++;
        else {
            ans=c;
            number=1;
        }
    }
    if(c>ans) return;
    for(int i=o+1;i<=r;i++) {
            if(a[o]+t>=a[i]) dfs(c+1,r,i,t);
            else return;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("migrate.in","r",stdin);
   freopen("migrate.out","w",stdout);

   ll c ,t;
   cin>>c>>t;
   if(1<=c and c<=10) {
    while(t--) {
        ll dp[310][310];
        ll n,d;
        cin>>n>>d;

        for(int i=1;i<=n;i++) {
            cin>>a[i];
        }
        ll anss=0;
        for(int len=2;len<=n;len++) {
            for(int i=1;i+len<=n;i++) {
                int j=i+len;
                ans=1E18,number=0;
                dfs(0,j,i,d);
                if(number==2) anss++;
            }
        }
        cout<<anss<<"\n";
   }
   }
    return 0;
}
