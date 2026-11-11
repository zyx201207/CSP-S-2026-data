#include<bits/stdc++.h>
#define ll int
#define inf 0x3f3f3f3f
#define N 1000005
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
vector<ll> op[N],has[N];
ll c,T,n,k,i,j,x,y,pos,pos2,ed,dep[N],lis[N],mxdep[N],tot,sta[N],top,vis[N],cnt1[N],cnt2[N],st1[N][21],st2[N][21],que[N],head,tail,cnts[N],incir[N],sum[N];
inline void dfs(ll x,ll fa){
    dep[x]=dep[fa]+1;
    if(dep[x]>dep[pos]) pos=x;
    for(ll i=0;i<op[x].size();i++) if(op[x][i]!=fa) dfs(op[x][i],x);
}
inline void found(ll x,ll fa){
    sta[++top] = x;
    if(x==ed){
        tot=top;
        for(ll i=1;i<=tot;i++) lis[i]=sta[i];
    }
    for(ll i=0;i<op[x].size();i++) if(op[x][i]!=fa) found(op[x][i],x);
    top--;
}
inline void dfs_lis(ll x,ll fa,ll rt){
    mxdep[x]=dep[x],vis[x]=1,has[rt].push_back(x);
    for(ll i=0;i<op[x].size();i++){
        if(vis[op[x][i]]) continue;
        dep[op[x][i]]=dep[x]+1,dfs_lis(op[x][i],x,rt);
        mxdep[x]=max(mxdep[x],mxdep[op[x][i]]);
    }
}
inline ll qry1(ll l,ll r){
    if(l>r) return -inf;
    ll c=log2(r-l+1);
    return max(st1[l][c],st1[r-(1<<c)+1][c]);
}
inline ll qry2(ll l,ll r){
    if(l>r) return -inf;
    ll c=log2(r-l+1);
    return max(st2[l][c],st2[r-(1<<c)+1][c]);
}
inline bool check(ll l,ll r,ll lim){
    if(l==r-1) return 1;
    ll mid=(l+r)/2;
    if(qry1(l+1,mid)-l>lim) return 0;
    if(qry2(mid+1,r-1)+r>lim) return 0;
    return 1;
}
inline void init(ll x,ll fa,ll lim){
    sum[x]=(mxdep[x]-dep[x]>=lim);
    for(ll i=0;i<op[x].size();i++){
        if(op[x][i]==fa||incir[op[x][i]]) continue;
        init(op[x][i],x,lim);
        sum[x]+=sum[op[x][i]];
    }
}
inline void solve(ll x,ll fa,ll lim,ll mx,ll &ans){
    if(fa!=0&&mx<=lim) ans=min(ans,max(sum[x],1));
    if(fa!=0) mx=max(mx,0);
    vector<ll> g(0),f1(0),f2(0);
    for(ll i=0;i<op[x].size();i++){
        if(op[x][i]==fa||incir[op[x][i]]) continue;
        g.push_back(op[x][i]);
    }
    if(g.size()==0) return ;
    f1.resize(g.size()),f2.resize(g.size());
    for(ll i=0,now=mx;i<g.size();i++){
        f1[i]=now;
        if(mxdep[g[i]]>lim) now=max(now,mxdep[g[i]]-dep[x]);
    }
    for(ll i=g.size()-1,now=mx;i>=0;i--){
        f2[i]=now;
        if(mxdep[g[i]]>lim) now=max(now,mxdep[g[i]]-dep[x]);
    }
    for(ll i=0;i<g.size();i++) solve(g[i],x,lim,max(f1[i],f2[i])+1,ans);
}
inline bool check(ll lim){
    ll res = inf;
    for(ll i=1;i<=tot;i++){
        if(i==1){cnt1[i]=1;continue;}
        cnt1[i]=cnt1[i-1];
        if(i-2>=lim) cnt1[i]++;
        for(ll j=0;j<has[lis[i]].size();j++){
            ll u=has[lis[i]][j];
            if(u==lis[i]) continue;
            if(mxdep[u]-dep[u]>=lim) cnt1[i]++;
        }
    }
    for(ll i=tot;i>=1;i--){
        if(i==tot){cnt2[i]=1;continue;}
        cnt2[i]=cnt2[i+1];
        if(tot-(i+1)>=lim) cnt2[i]++;
        for(ll j=0;j<has[lis[i]].size();j++){
            ll u=has[lis[i]][j];
            if(u==lis[i]) continue;
            if(mxdep[u]-dep[u]>=lim) cnt2[i]++;
        }
    }
    // for(ll i=1;i<=tot;i++) cout<<lis[i]<<" ";
    // cout<<endl;
    // for(ll i=1;i<=tot;i++) cout<<cnt1[i]<<" ";
    // cout<<endl;
    // for(ll i=1;i<=tot;i++) cout<<cnt2[i]<<" ";
    // cout<<endl;
    for(ll i=1;i<=tot;i++) if(tot-i<=lim) res=min(res,cnt1[i]);
    head=1,tail=0;
    for(ll i=tot;i>=1;i--){
        while(head<=tail&&!check(i,que[head],lim)) head++;
        if(head<=tail) res=min(res,cnt1[i]+cnt2[que[head]]);
        while(head<=tail&&cnt2[que[tail]]>=cnt2[i]) tail--;
        que[++tail]=i;
    }
    if(1+lim<=tot-lim){
        ll nowcnt=0;
        for(ll i=1+lim;i<=tot-lim;i++){
            nowcnt++,cnts[i]=0;
            for(ll j=0;j<has[lis[i]].size();j++){
                ll u=has[lis[i]][j];
                if(u==lis[i]) continue;
                if(mxdep[u]-dep[u]>=lim) cnts[i]++,nowcnt++;
            }
        }
        res=min(res,nowcnt);
        for(ll i=1+lim;i<=tot-lim;i++){
            ll res2=nowcnt-cnts[i],res3=inf;
            init(lis[i],0,lim);
            solve(lis[i],0,lim,-inf,res3);
            // cerr<<"!! "<<lis[i]<<" "<<res2<<" "<<res3<<endl;
            res=min(res,res2+res3);
        }
    }
    return res<=k;
}
inline ll solve(ll S,ll T){
    ed=T,found(S,0);
    for(i=1;i<=tot;i++) vis[lis[i]]=1,incir[lis[i]]=1;
    for(i=1;i<=tot;i++) dep[lis[i]]=0,dfs_lis(lis[i],0,lis[i]);
    for(i=tot;i>=1;i--){
        st1[i][0]=mxdep[lis[i]]+i;
        st2[i][0]=mxdep[lis[i]]-i;
        for(j=1;i+(1<<j)-1<=tot;j++){
            st1[i][j]=max(st1[i][j-1],st1[i+(1<<j-1)][j-1]);
            st2[i][j]=max(st2[i][j-1],st2[i+(1<<j-1)][j-1]);
        }
    }
    ll l=0,r=n;
    while(l<r){
        ll mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    for(i=1;i<=n;i++) vis[i]=0,has[i].clear(),incir[i]=0;
    return l;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read(),T=read();
    while(T--){
        n=read(),k=read(),pos=1,pos2=1;
        for(i=1;i<n;i++) x=read(),y=read(),op[x].push_back(y),op[y].push_back(x);
        dfs(1,0),pos2=pos,dfs(pos,0);
        vector<ll> emp(0);
        // cout<<dep[14]<<" "<<dep[9]<<" "<<pos2<<endl;
        // for(i=1;i<=n;i++) cout<<dep[i]<<" ";
        // cout<<endl;
        for(i=1;i<=n;i++) if(dep[i]==dep[pos]) emp.push_back(i);
        ll ans=0x3f3f3f3f;
        // cout<<"!!! "<<emp.size()<<"\n";
        ans=min(ans,solve(pos2,emp[0]));
        if(emp.size()>=2) ans=min(ans,solve(pos2,emp[1]));
        printf("%d\n",ans);
        for(i=1;i<=n;i++) op[i].clear();
    }
    return 0;
}
