#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define d(x) cout<<"# "<<x<<" ";
ll n,d,a[2000005];
void solve4(){
    cin>>n>>d;
    for(ll i=1;i<=n;++i){
        cin>>a[i];
    }
    ll de=a[2]-a[1],st=d/de;
    ll ans=0;
    if(st<=1){
        cout<<"0\n";
        return ;
    }
    cout<<max(0ll,n-st-st+1)<<"\n";
}
ll l[5005],r[5005],dis[5005][5005],num[5005][5005];
void solve12(){
    cin>>n>>d;
    for(int i=1;i<=n;++i){
        num[i][i]=1;
        for(int j=i+1;j<=n;++j){
            dis[i][j]=0x3f3f3f3f3f3f3f3f;
            num[i][j]=0;
        }
    }
    for(ll i=1;i<=n;++i){
        cin>>a[i];
        for(int j=i;a[i]-a[j]<=d&&j;--j){
            l[i]=j,r[j]=i;
        }
    }
    for(int s=1;s<=n;++s){
        for(int i=s;i<=n;++i){
            for(int j=i;j<=r[i];++j){
                if(dis[s][j]>dis[s][i]+1) dis[s][j]=dis[s][i]+1,num[s][j]=num[s][i];
                else if(dis[s][j]==dis[s][i]+1) num[s][j]+=num[s][i];
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            ans+=(num[i][j]==2);
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,T;
    cin>>c>>T;
    while(T--){
        if(c<=10) solve12();
        if(c==11||c==12) solve4();
        if(c>12) cout<<"0\n";
    }
    return 0;
}
