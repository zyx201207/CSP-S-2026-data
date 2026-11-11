#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int n,a[N],d;
int flg=1;
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    int flg=1;
    int gc=abs(a[2]-a[1]);
    for(int i=3;i<=n;i++){
        if(abs(a[i]-a[i-1])!=gc)flg=0;
    }
    if(flg==1){
        if(gc>=d){
            cout<<0<<"\n";
            return ;
        }
        int t=d/gc;
        if(t==1){cout<<0<<"\n";return ;}
        if(n+1<=t*2){cout<<0<<"\n";return ;}
        cout<<n-2*t+1<<"\n";
    }
}
void solve2(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    int sum=0,ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            sum=0;int flg=0;
            for(int k=i+1;k<=j;k++){
                sum+=a[k]-a[k-1];
                if(sum>d){
                    flg++;
                    // sum=a[k]-a[k-1];
                }
            }
            if(flg==1&&sum==d*2+1)ans++;
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T,C;cin>>C>>T;
    while(T--){
        if(C==11||C==12)solve();
        else solve2();
    }
    return 0;
}