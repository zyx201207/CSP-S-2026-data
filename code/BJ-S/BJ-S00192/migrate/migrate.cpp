#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n,m,ans=0;
    cin>>n>>m;
    vector<int>a(n+1);
    bool b=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>2&&((a[i]-a[i-1])!=(a[i-1]-a[i-2])))b=0;
    }
    if(b){
        if(m>(a[2]-a[1]))cout<<max(0ll,n-(m/(a[2]-a[1]))*2+1)<<"\n";
        else cout<<"0\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(i>=3){
            if((a[i]-a[i-3]>m)&&(a[i]-a[i-2]<=m)&&(a[i-1]-a[i-3]<=m)){
                int x=i-4,y=i+1;
                while(x>=0&&a[x+1]-a[x]<=m&&a[x+2]-a[x]>m)x--;
                while(y<n&&a[y]-a[y-1]<=m&&(a[y]-a[y-2]>m))y++;
                ans+=(i-3-x)*(y-i);
            }
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--) solve();
    return 0;
}
