#include<bits/stdc++.h>

#define int long long

int c,T;

const int N=2000005;

int n,d;
int a[N];
int pre[N],nxt[N];
int pt[N],nt[N];
int fp[N],fn[N];
int ans;

void run(){
    std::cin>>n>>d;
    for(int i=0;i<=n+1;i++) a[i]=pre[i]=nxt[i]=pt[i]=nt[i]=fp[i]=fn[i]=0;
    for(int i=1;i<=n;i++) std::cin>>a[i];

    int p=n;
    for(int i=n;i>=1;i--){
        while(a[p]>a[i]+d) --p;
        nxt[i]=p;
    }
    p=1;
    for(int i=1;i<=n;i++){
        while(a[i]>a[p]+d) ++p;
        pre[i]=p;
    }
    
    p=n+1;
    for(int i=n;i>=1;i--){
        if(nxt[i]>i){
            p=std::min(p,nxt[i]+1);
            while(pre[p-1]==i) --p;
            nt[i]=p;
            fn[i]=nxt[i]-p+1;
            if(pre[nxt[i]]==i) fn[i]+=fn[nxt[i]];
        }
    }

    p=0;
    for(int i=1;i<=n;i++){
        if(pre[i]<i){
            p=std::max(p,pre[i]-1);
            while(nxt[p+1]==i) ++p;
            pt[i]=p;
            fp[i]=p-pre[i]+1;
            if(nxt[pre[i]]==i) fp[i]+=fp[pre[i]];
        }
    }

    ans=0;
    for(int i=2;i+1<n;i++){
        if(pre[i]!=i&&nxt[i+1]!=i+1&&a[i+1]-a[i]<=d){
            int lv=0,rv=0;
            if(nxt[pre[i]]==i+1){
                lv=fp[pre[i]];
            }
            if(pre[nxt[i+1]]==i){
                rv=fn[nxt[i+1]];
            }
            int L=pre[i+1],R=nxt[i];
            if(L<=std::min(pt[i+1],i-1))
                lv+=std::min(pt[i+1],i-1)-L+1;
            if(R>=std::max(nt[i],i+2))
                rv+=R-std::max(nt[i],i+2)+1;
            ans+=lv*rv;
        }
    }
    std::cout<<ans<<'\n';

    return;
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(0),std::cout.tie(0);
    
    std::cin>>c>>T;
    while(T--) run();

    return 0;
}
