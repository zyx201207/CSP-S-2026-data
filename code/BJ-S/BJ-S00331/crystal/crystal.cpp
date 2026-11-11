#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],s[N],pre[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    s[1]=0;
    pre[1]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        s[i]=a[i]-a[i-1];
    }
    for(int i=2;i<=n;i++){
        pre[i]=s[i]+pre[i-1];
        //cout<<pre[i]<<' ';
    }
    int h=1,t=1;
    ll ans=0;
    ll cnt=0;
    while(t<=n){
        ll len=t-h+1;
        if(cnt<=m){
            ans=max(ans,len);
            t++;
            cnt+=len*s[t];
        }
        else{
             cnt-=pre[t]-pre[h];
             h++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
