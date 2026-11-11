#include<bits/stdc++.h>
#define ll long long
#define N 2000005
using namespace std;
inline char nc(){
    static char buf[1000005],*p(buf),*q(buf);
    return p==q&&(q=(p=buf)+fread(buf,1,1000000,stdin),p==q)?EOF:*p++;
}
inline ll read(){
    ll res=0,w=1;
    char c=nc();
    while(c<'0'||c>'9') w=(c=='-'?-1:w),c=nc();
    while(c>='0'&&c<='9') res=res*10+c-'0',c=nc();
    return res*w;
}
vector<ll> to1[N],to2[N];
ll c,T,n,d,x[N],i,j,ans,lef[N],rih[N],len1[N],len2[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),T=read();
    while(T--){
        n=read(),d=read(),ans=0;
        for(i=1;i<=n;i++) x[i]=read();
        for(i=1,j=1;i<=n;i++){
            while(x[i]-x[j]>d) j++;
            lef[i]=j;
        }
        for(i=n,j=n;i>=1;i--){
            while(x[j]-x[i]>d) j--;
            rih[i]=j;
        }
        for(i=1;i<=n;i++) to1[lef[i]].push_back(i),to2[rih[i]].push_back(i);
        for(i=1;i<=n;i++){
            len1[i]=1;
            if(lef[i]!=i&&rih[lef[i]]==i) len1[i]+=len1[lef[i]];
            for(j=0;j<to2[i].size();j++) len1[i]+=(to2[i][j]<i&&to2[i][j]>lef[i]);
        }
        for(i=n;i>=1;i--){
            len2[i]=1;
            if(rih[i]!=i&&lef[rih[i]]==i) len2[i]+=len2[rih[i]];
            for(j=0;j<to1[i].size();j++) len2[i]+=(to1[i][j]>i&&to1[i][j]<rih[i]);
        }
        for(i=1;i<n;i++){
            if(rih[i+1]==i+1||lef[i]==i) continue;
            ll val1=0,val2=0;
            if(rih[lef[i]]==i+1) val1+=len1[lef[i]];
            if(lef[rih[i+1]]==i) val2+=len2[rih[i+1]];
            for(j=0;j<to2[i+1].size();j++) val1+=(to2[i+1][j]<i&&to2[i+1][j]>lef[i]);
            for(j=0;j<to1[i].size();j++) val2+=(to1[i][j]>i+1&&to1[i][j]<rih[i+1]);
            ans+=val1*val2;
        }
        printf("%lld\n",ans);
        for(i=1;i<=n;i++) to1[i].clear(),to2[i].clear();
    }
    return 0;
}