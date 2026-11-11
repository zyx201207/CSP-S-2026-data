#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
ll c,t,n,d,f[N],x[N],ans;
ll v[N],sum[N];
void wk(int st){
    //memset(f,0,sizeof(f));
    int j=st;f[st]=0;int cnt,k=st;
    for(int i=st;i<=n;i++) v[i]=0;
    v[st]=1;sum[st]=1;sum[st-1]=0;
    for(int i=st+1;i<=n;i++){
        //cout<<x[i]<<' '<<x[j]<<' '<<d<<' ';
        while(x[i]-x[j]>d&&j<i) j++;
        if(i==j) return;
        while(f[k+1]<=f[j]&&k+1<i) k++;
        f[i]=f[j]+1;
        v[i]=sum[k]-sum[j-1];
        sum[i]=sum[i-1]+v[i];
        //cout<<j<<' '<<k<<'\n';
        if(v[i]==2) ans++;
    }
}
bool check(){
    for(int i=3;i<=n;i++) if(x[i]-x[i-1]!=x[2]-x[1]) return 0;
    return 1;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;ans=0;
        for(int i=1;i<=n;i++) cin>>x[i];
        if(check()&&n>5000){
            if(3*(x[2]-x[1])<=d) cout<<0<<'\n';
            else if(2*(x[2]-x[1])<=d) cout<<n-3<<'\n';
            else cout<<0<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++) wk(i);
        cout<<ans<<'\n';
    }
    return 0;
}
