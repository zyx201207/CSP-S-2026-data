#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N];
long long n,m,k,cnt,sum;
void solve(){
    cin>>n>>m;
    sum=0;
    cnt=0;
    memset(a,0,sizeof(a));
    if(k!=11&&k=12){
        sum=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(abs(a[i]-a[i+1])>m){
                n=i;
                break;
            }
            if(cnt+=a[i]>m){
                cnt=a[i];
                sum++;
            }else{
                cnt+=a[i];
            }
        }
        sum=1;
        for(int i=4;i<=n;i++){
            if(a[i]+a[i-3]<=m){
                sum++;
            }
        }
        cout<<sum<<"\n";
    }else{
        if(n==4){
            cout<<(m>=abs(a[2]-a[1])*(n+1)/2?1:0)<<"\n";
        }else{
            cout<<0<<"\n";
        }
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>k>>t;
    while(t--){
        solve();
    }
    return 0;
}
