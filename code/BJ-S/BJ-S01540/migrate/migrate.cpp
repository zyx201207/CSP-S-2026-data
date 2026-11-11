#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2000002;
int c,t,n;
ll d,x[maxn];
int nxt[maxn];
int L[maxn],R[maxn];
int st[maxn],ed[maxn];
int way[maxn],pre[maxn];
ll solveN(int n,ll d){
    int j=1;
    for(int i=1;i<=n;i++){
        j=max(j,i);
        while(j+1<=n&&x[j+1]-x[i]<=d)++j;
        nxt[i]=j;
    }
    ll ans=0;
    for(int i=1;i<=n-1;i++){
        if(nxt[i]==i)continue;
        int lcur=i+1,rcur=nxt[i];
        for(int j=lcur;j<=rcur;j++)way[j]=1;
        while(true){
            int len=rcur-lcur+1;pre[0]=0;
            for(int j=0;j<len;j++)pre[j+1]=pre[j]+way[lcur+j];
            int rnxt=nxt[rcur];
            if(rnxt==rcur)break;
            int lnxt=rcur+1,pos=lcur;
            for(int j=lnxt;j<=rnxt;j++){
                while(pos<=rcur&&x[pos]+d<x[j])++pos;
                int w=0;
                if(pos<=rcur)w=min(pre[rcur-lcur+1]-pre[pos-lcur],3);
                way[j]=w;
                if(w==2)++ans;
            }
            lcur=lnxt;rcur=rnxt;
        }
    }
    return ans;
}
ll solveA(int n,ll d){
    if(n<2)return 0;
    if(x[2]<=x[1])return 0;
    ll q=d*(x[2]-x[1]);
    if(q>=n-1)return 0;
    if(q<2)return 0;
    ll s=2*q-1;
    if(s>n-1)return 0;
    return n-s;
}
ll solveB(int n,ll d){
    int p=1;
    for(int i=1;i<=n;i++){
        while(p<=n&&x[i]-x[p]>d)++p;
        L[i]=p;
    }
    int q=1;
    for(int i=1;i<=n;i++){
        while(q<=n&&x[q]-x[i]<=d)++q;
        R[i]=q-1;
    }
    for(int i=1;i<=n;i++)st[i]=ed[i]=0;
    for(int i=1;i<=n;i++){
        if(st[L[i]]==0)st[L[i]]=i;
        ed[L[i]]=i;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(R[i]>1&&st[R[i]-1]!=0){
            int lpos=max(st[R[i]-1],R[i]+1),rpos=ed[R[i]-1];
            if(lpos<=rpos)ans+=rpos-lpos+1;
        }
    }
    return ans;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        ll ans;
        if(c>=11&&c<=12)ans=solveA(n,d);
        else if(c>=13&&c<=14)ans=solveB(n,d);
        else ans=solveN(n,d);
        cout<<ans<<endl;
    }
    return 0;
}
//*-*
// ~ ℹ LOVE U ~