#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,w[50005],xr,yr,nb,tn,minn;
struct roads{ll z[50005],t[25],ans=1,ac;bool vis[50005]={0},ft=1;}a[505];
void f(ll x){
    if(x==yr){
        minn=min(minn,tn);
        return;
    }
    for(ll i=1;i<=n;i++){
        if((a[i].vis[x]==0)||(a[i].ft==0))continue;
        tn+=a[i].t[x];
        for(ll j=1;j<=a[i].ac;j++){
            tn+=a[i].t[a[i].z[j]];
            a[i].ft=0;
            f(a[i].z[j]);
            a[i].ft=1;
            tn-=a[i].t[a[i].z[j]];
        }
    }

}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++){
        cin>>w[i];
    }
    for(ll i=1;i<=n;i++){
        cin>>a[i].ac;
        for(ll j=1;j<=a[i].ac;j++){
            cin>>a[i].z[a[i].ans++];
            a[i].vis[a[i].z[a[i].ans-1]]=1;
            cin>>a[i].t[a[i].z[a[i].ans-1]];
        }
    }
    while(q--){
        cin>>xr>>yr;
        minn=1000000000000;
        tn=w[xr]+w[yr];
        f(xr);
        cout<<minn<<endl;
    }
    return 0;
}
