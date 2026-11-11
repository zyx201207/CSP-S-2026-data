#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005;
ll pre[N],cha[N],a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",std.in);
    freopen("crystal.out","w",std.out);
    ll n,m,x,y,cnt=0;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
     for(ll i=1;i<=n-1;i++){
        cha[i]=a[i+1]-a[i];
    }
    pre[0]=0;
    for(ll i=1;i<=n-1;i++){
        pre[i]=pre[i-1]+cha[i]*i;
    }
    if(pre[n-1]<=m){
        cout<<n;
        return 0;
    }
    for(ll i=1;i<=n-1;i++){
        for(ll j=0;j<i;j++){
            if(pre[i]-pre[j]<=m){
                if(cnt<i-j){
                    cnt=i-j;
                }
            }
        }
    }
    cout<<cnt+1;
    return 0;
}

