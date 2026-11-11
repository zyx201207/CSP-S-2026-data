#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int a[N],b[N],c;
void solve(){
    int n,d;cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==1){
        cout<<"0\n";
    }if(c>10){
        cout<<max(0ll,n-2*(d/(a[2]-a[1]))+1)<<"\n";
        return;
    }
    int ans=0;
    for(int x=1;x<=n;x++){
        for(int y=x+1;y<=n;y++){
            int now=x,cur=0,op=0;
            while(true){
                b[++cur]=now;
                if(a[now+1]-a[now]>d){
                    op=1;break;
                }if(a[y]-a[now]<=d)break;
                for(int i=now+1;i<=n;i++){
                    if(a[i]-a[now]<=d && a[i+1]-a[now]>d){
                        now=i;break;
                    }
                }
            }if(op)continue;
            b[++cur]=y;
            int sum=0;now=0;
            for(int i=x;i<=y;i++){
                if(i==b[now+1]){
                    now++;continue;
                }sum+=(a[b[now+2]]-a[i]<=d && now+2<=cur);
                sum+=(a[i]-a[b[now-1]]<=d && now-1>=1);
                if(sum>=2)break;
            }ans+=(sum==1);
        }
    }cout<<ans<<"\n";
    return;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>c>>t;
    while(t--)solve();
    return 0;
}
