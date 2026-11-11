#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=5e5+10;
ll cf[maxn],a[maxn],n,m,cnt;
ll qzh[maxn],ans,res[maxn];
//qztrp++
void qzt(ll x){
    for(int i=1;i<=n;i++){
        qzh[i]=0;
    }
    ll add=0,cnt=0;
    for(ll i=1;i<=n;i++){
        qzh[i]=abs(cf[i]-cf[x]);
    }
    sort(qzh+1,qzh+n+1);
    for(ll i=1;i<=n;i++){
        if(add+qzh[i]<=m){
            cnt++;
            add+=qzh[i];
        }else break;
    }
    res[x]=cnt;

}
int main(){
//    freopen("crystal.in","r",stdin);
//    freopen("crystal.out",'w',stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    
    sort(a+1,a+n+1);

    cf[1]=0;
    for(ll i=2;i<=n;i++){
        cf[i]=a[i]-a[i-1];
    }
    for(ll i=1;i<=n;i++){
        cf[i]=cf[i-1]+cf[i];
    }
    for(int i=1;i<=n;i++){
        qzt(i);
    }
    for(ll i=1;i<=n;i++){
        ans=max(res[i],ans);
    }
        cout<<ans;
    //}
    return 0;
}