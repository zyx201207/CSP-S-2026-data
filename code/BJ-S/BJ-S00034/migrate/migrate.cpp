#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
const long long INF=0x3f3f3f3f3f3f3f3f+9;
const int N=2e6+10;
long long a[N],la[N],ua[N];
unordered_map<long long,bool> ump;
void solve(){
    ump.clear();
    long long m;
    int n;
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ump[a[i]]=true;
    }
    for(int i=1;i<=n;i++){
        la[i]=lower_bound(a+1,a+1+n,a[i]-m)-a;
        ua[i]=upper_bound(a+1,a+1+n,a[i]+m)-1-a;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]-a[i]>=2*m){
                break;
            }else if(a[j]-a[i]<=m) continue;
            if(ua[i]-la[j]==1) ans++;
        }
    }
    cout<<ans;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int c,t;
    cin>>c>>t;
    a[0]=INF;
    while(t--){
        solve();
        cout<<'\n';
    }
    return 0;
}
