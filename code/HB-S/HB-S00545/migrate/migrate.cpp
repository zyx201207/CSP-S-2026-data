#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int cid,n;
ll d;
ll a[N];
ll f[N][2];
int lp[N],rp[N];
ll cnt[N];
ll g[N]; 
ll op[N];
void work(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<=n;i++) f[i][0]=f[i][1]=0,g[i]=0,op[i]=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i,pos=i;
        while(l<=r){
            int mid=l+r>>1;
            if((a[i]-a[mid])<=d) pos=mid,r=mid-1;
            else l=mid+1;
        }
        lp[i]=pos; 
        l=i,r=n,pos=i;
        while(l<=r){
            int mid=l+r>>1;
            if((a[mid]-a[i])<=d) pos=mid,l=mid+1;
            else r=mid-1;
        }
        rp[i]=pos;
        l=lp[i],r=i-1,pos=i;
        while(l<=r){
            int mid=l+r>>1;
            if(rp[mid]==i) pos=mid,l=mid+1;
            else r=mid-1;
        }
        cnt[i]=(i-1)-pos+1;
    }  
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(lp[i]<lp[i+1]){
            if(rp[lp[i]-1]!=i) op[i]+=op[lp[i]]; 
            op[i]+=lp[i+1]-lp[i]; 
        }
    }
    for(int i=1;i<=n;i++){
        if(lp[i]==1) continue;
        if(lp[i]==i) continue;
        int x=lp[i];
        f[i][0]=f[x][0];
        f[i][0]+=lp[x+1]-lp[x];
        int y=x+1;
        if(y==i){
            if(lp[x]<x) f[i][1]+=f[x][1];
        }
        else{
            if(lp[y]==lp[x]+1){
                f[i][1]+=f[x][1]-g[x];
            }
            else if(lp[y]>lp[x]+1){
                f[i][1]+=f[x][1];
            } 
            if(lp[y]<lp[y+1]){
                g[i]+=lp[y+1]-lp[y];
                if(rp[lp[y]-1]!=x) g[i]+=op[lp[y]];
            } 
            f[i][1]+=g[i];
        }
    } 
    for(int i=1;i<=n;i++){ ans+=f[i][1];} 
    cout<<ans<<"\n";
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T;cin>>cid>>T;
    while(T--) work();
    return 0;
}