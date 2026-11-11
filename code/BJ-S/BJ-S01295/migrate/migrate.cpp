#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int T,c,n,ans;
ll a[N],d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d,ans=0;
        for(int i=1;i<=n;i++){cin>>a[i];}
        sort(a+1,a+n+1);
        if(d>=a[n]-a[1]){
            cout<<0<<'\n';continue;
        }
        for(int i=1;i<=n;i++){
            int u=int(lower_bound(a+i,a+n+1,a[i]+d)-a);
            int v=min(int(lower_bound(a+i,a+n+1,a[i]+2*d)-a),n);
            if(u==v)continue;
            for(int j=u;j<=v;j++){
                if(a[j]-a[i]==2*d&&(a[j]-a[i+1]>d||a[j-1]-a[i]>d))continue;
                if(a[j]-a[i]>2*d)continue;
                if(a[j]-a[i]>d&&j-i-1>2)continue;
                if(a[j]-a[i]==d)continue;
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    return 0;
}