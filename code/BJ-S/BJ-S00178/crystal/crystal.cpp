#include <bits/stdc++.h>
#define rep(i,s,t) for(ll i=s;i<=t;i++)
#define ll long long
#define int long long
#define mid (l+r)/2
using namespace std;
ll inf=10000000000000;
int n;
ll a[500005],ans,m,sumv[500005],maxx[20000006];
void bui(int id,int l,int r){
    if(l==r){
        maxx[id]=a[l];
        return ;
    }
    bui(id*2,l,mid);
    bui(id*2+1,mid+1,r);
    maxx[id]=max(maxx[id*2],maxx[id*2+1]);
}
ll get(int id,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        return maxx[id];
    }
    ll ans1=-inf;
    if(x<=mid){
            ans1=max(ans1,get(id*2,l,mid,x,y));
    }
    if(y>mid){
            ans1=max(ans1,get(id*2+1,mid+1,r,x,y));
    }
    return ans1;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    rep(i,1,n){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    rep(i,1,n){
        sumv[i]=sumv[i-1]+a[i];
    }
    bui(1,1,n);
    ll j=1;
    rep(i,1,n){
        while(j<i){
            ll tmp=get(1,1,n,j,i);
          //  cout<<i<<' '<<j<<' '<<tmp<<' '<<(i-j+1)<<' '<<-sumv[i]+sumv[j-1]<<' '<<tmp*(i-j+1)-sumv[i]+sumv[j-1]<<endl;
            if(tmp*(i-j+1)-sumv[i]+sumv[j-1]<=m){
                break;
            }
            j++;
        }
        ans=max(ans,(ll)i-j+1);
    }
    printf("%lld",ans);
    return 0;
}
//10 20
//4 2 4 6 3 8 6 2 4 23
