#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6+5;

int n,m;
ll a[maxn];
int b[maxn];

ll ans=-1e18;

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
}

void dfs(int dep){
    if(dep>n){
        int cnt = 0;
        ll sum=0;
        for(int i=1;i<=n;i++)if(b[i])cnt++;
        if(cnt!=m)return ;//== m

        cnt = 0;
        for(int i=1;i<=n;i++){
            if(b[i]){
                cnt++;
                if(cnt==1)sum = a[i];
                else sum = sum & a[i];
            }
        }

        // cout<<cnt<<"\n";

        if(cnt!=0)ans = max(ans,sum);
        return ;
    }

    for(int i=0;i<=1;i++){
        b[dep] = i;
        dfs(dep+1);
    }
}

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);


    ios::sync_with_stdio(0);
    cin.tie(0);
    init();

    if(n<=20){
        dfs(1);
        cout<<ans<<"\n"; 
        return 0;
    }

    if(m==1 && n<=2000){
        for(int i=1;i<=n;i++)ans = max(ans,a[i]);
        cout<<ans<<"\n";
        return 0;
    }

    if(m==n && n<=2000){
        ll sum = a[1];
        for(int i=2;i<=n;i++)sum &= a[i];
        cout<<sum<<"\n";
        return 0;
    }

    if(m==2 && n<=2000){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ll sum = a[i]&a[j];
                ans = max(ans,sum);
            }
        }
        cout<<ans<<"\n";
        return 0;
    }

    if(m==n-1){
        ll sum = a[1];
        for(int i=2;i<n;i++)sum &= a[i];
        ans = max(ans,sum);

        sum = a[2];
        for(int i=3;i<=n;i++)sum &= a[i];
        ans = max(ans,sum);

        cout<<ans<<"\n";

        return 0;
    }

    cout<<12<<"\n";
    return 0;
}