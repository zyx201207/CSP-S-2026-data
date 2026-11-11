#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct shu{ll l,mid,r;};
struct chk{
    ll fa,now,len;
    bool operator<(const chk &o)const{
        if(len!=o.len)return len<o.len;
        return now<o.now;
    }
};
ll c,T;
ll n,k;
vector<ll> v[1000005];
ll dep[1000005],f[1000005];
shu mid,mid1,mid2;
void getdep(ll now,ll fa,ll cut1){
    dep[now]=1;
    if(f[now]==0&&now!=1)f[now]=fa;
    for(auto i:v[now]){
        if(i==fa)continue;
        if(i==cut1)continue;
        getdep(i,now,cut1);
        dep[now]=max(dep[now],dep[i]+1);
    }
}
shu getmid(ll now,ll fa,ll upl){
    ll maxn=0,secn=0;
    for(auto i:v[now]){
        if(i==fa)continue;
        if(dep[maxn]<dep[i])secn=maxn,maxn=i;
        else if(dep[secn]<dep[i])secn=i;
    }
    if(dep[maxn]-2<upl)return {fa,now,maxn};
    return getmid(maxn,now,max(upl+1,dep[secn]));
}
ll getlen(ll Now,ll Fa,ll cut1,ll K){
    priority_queue<chk> q;
    q.push(chk{Fa,Now,dep[Now]});
    for(ll i=1;i<=K;i++){
        ll now=q.top().now,fa=q.top().fa;
        q.pop();
        for(auto j:v[now]){
            if(j==fa)continue;
            if(j==cut1)continue;
            q.push(chk{now,j,dep[j]});
        }
        if(q.empty())return 0;
    }
    return q.top().len;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(ll i=1;i<=n;i++)dep[i]=0,f[i]=0;
        for(ll i=1;i<=n;i++)v[i].clear();
        for(ll i=1,u1,v1;i<n;i++){
            cin>>u1>>v1;
            v[u1].push_back(v1);
            v[v1].push_back(u1);
        }
        if(n*n*20>=5e8){
            getdep(1,0,0);
            mid=getmid(1,0,0);
            getdep(mid.mid,0,0);
            ll nowans=getlen(mid.mid,0,0,k);
            for(ll i=1;i<=n;i++)dep[i]=0;
            getdep(mid.mid,mid.l,0);
            getdep(mid.l,mid.mid,0);
            mid1=getmid(mid.mid,mid.l,0);
            mid2=getmid(mid.l,mid.mid,0);
            for(ll i=1;i<=n;i++)dep[i]=0;
            getdep(mid1.mid,0,mid.l);
            getdep(mid2.mid,0,mid.mid);
            ll l=1,r=k-1,ans1=1;
            while(l<=r){
                ll MID=(l+r)/2;
                if(getlen(mid1.mid,0,mid.l,MID)<=getlen(mid2.mid,0,mid.mid,k-MID))r=MID-1,ans1=MID;
                else l=MID+1;
            }
            nowans=min(nowans,max(getlen(mid1.mid,0,mid.l,ans1),getlen(mid2.mid,0,mid.mid,k-ans1)));
            for(ll i=1;i<=n;i++)dep[i]=0;
            getdep(mid.mid,mid.r,0);
            getdep(mid.r,mid.mid,0);
            mid1=getmid(mid.mid,mid.r,0);
            mid2=getmid(mid.r,mid.mid,0);
            for(ll i=1;i<=n;i++)dep[i]=0;
            getdep(mid1.mid,0,mid.r);
            getdep(mid2.mid,0,mid.mid);
            l=1,r=k-1,ans1=1;
            while(l<=r){
                ll MID=(l+r)/2;
                if(getlen(mid1.mid,0,mid.r,MID)<=getlen(mid2.mid,0,mid.mid,k-MID))r=MID-1,ans1=MID;
                else l=MID+1;
            }
            nowans=min(nowans,max(getlen(mid1.mid,0,mid.r,ans1),getlen(mid2.mid,0,mid.mid,k-ans1)));
            cout<<nowans<<endl;
            continue;
        }
        getdep(1,0,0);
        ll nowans=getlen(1,0,0,k);
        for(ll i=2;i<=n;i++){
            getdep(i,0,0);
            nowans=min(nowans,getlen(i,0,0,k));
            for(ll i=1;i<=n;i++)dep[i]=0;
            getdep(i,f[i],0);
            getdep(f[i],i,0);
            mid1=getmid(i,f[i],0);
            mid2=getmid(f[i],i,0);
            for(ll i=1;i<=n;i++)dep[i]=0;
            getdep(mid1.mid,0,f[i]);
            getdep(mid2.mid,0,i);
            ll l=1,r=k-1,ans1=1;
            while(l<=r){
                ll MID=(l+r)/2;
                if(getlen(mid1.mid,0,f[i],MID)<=getlen(mid2.mid,0,i,k-MID))r=MID-1,ans1=MID;
                else l=MID+1;
            }
            nowans=min(nowans,max(getlen(mid1.mid,0,f[i],ans1),getlen(mid2.mid,0,i,k-ans1)));
        }
        cout<<nowans<<endl;
    }
    return 0;
}
