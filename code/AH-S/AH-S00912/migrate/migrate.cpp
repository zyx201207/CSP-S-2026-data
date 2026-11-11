#include <bits/stdc++.h>
using namespace std;

const int N=2e6+5;
long long a[N];
int nxt[N],lst[N],ln[N],rn[N],ls[N],rs[N];
long long snxt[N],slst[N];
int solve(int l1,int r1,int l2,int r2){
    if (l1>r1||l2>r2) return 0;
    if (r1<l2||r2<l1) return 0;
    int sl=max(l1,l2),sr=min(r1,r2);
    return max(sr-sl+1,0);
}
void work2(){
    int n;long long d;
    cin>>n>>d;
    for(int i=1;i<=n;i++) lst[i]=nxt[i]=slst[i]=snxt[i]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    int wp=1;
    for(int i=1;i<=n;i++){
        while(a[i]-a[wp]>d) wp++;
        lst[i]=wp;
    }
    wp=n;
    for(int i=n;i>=1;i--){
        while(a[wp]-a[i]>d) wp--;
        nxt[i]=wp;
    }
    for(int i=1;i<=n;i++) ls[i]=ln[i]=n+1,rs[i]=rn[i]=0;
    for(int i=1;i<=n;i++){
        ln[nxt[i]]=min(ln[nxt[i]],i);
        ls[lst[i]]=min(ls[lst[i]],i);
        rn[nxt[i]]=max(rn[nxt[i]],i);
        rs[lst[i]]=max(rs[lst[i]],i);
    }
    for(int i=1;i<=n;i++){
        snxt[i]++;snxt[i]+=max(rn[i]-ln[i],0);
        if (nxt[i]!=i)if (lst[nxt[i]]==i)snxt[nxt[i]]+=snxt[i];
    }
    for(int i=n;i>=1;i--){
        slst[i]++;slst[i]+=max(rs[i]-ls[i],0);
        if (lst[i]!=i)if (nxt[lst[i]]==i)slst[lst[i]]+=slst[i];
    }
    long long ans=0;
    for(int i=2;i<n-1;i++){
        long long g1=0,g2=0;
        if (nxt[i+1]==i+1||lst[i]==i) continue;
        if (lst[nxt[i+1]]==i) g1+=slst[nxt[i+1]];
        if (nxt[lst[i]]==i+1) g2+=snxt[lst[i]];
        int lp=i+2,rp=nxt[i+1]-1;
        g1+=solve(lp,rp,ls[i],rs[i]);
        lp=lst[i]+1,rp=i-1;
        g2+=solve(lp,rp,ln[i+1],rn[i+1]);
        ans+=g1*g2;
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--) work2();
    return 0;
}