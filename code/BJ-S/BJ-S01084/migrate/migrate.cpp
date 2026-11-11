#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
#define FOR(i,a,b) for(int i=(a),EEEE##i=(b); i<=EEEE##i; i++)
#define REV(i,a,b) for(int i=(a),EEEE##i=(b); i>=EEEE##i; i--)
#define endl '\n'
template<typename T>
void outval_(string s,int p,const T& t){cerr<<s.substr(p,s.size()-p)<<"="<<t<<endl;}
template<typename T,typename... Args>
void outval_(string s,int p,const T& t,const Args& ...rest){
    while(s[p]!=',') cerr<<s[p++]; cerr<<"="<<t<<"  ";
    outval_(s,p+1,rest...);}
#define outval(...) outval_(#__VA_ARGS__,0,__VA_ARGS__)
#define outarr(aaa,beee,eddd)\
{cerr<<(#aaa)<<": "; FOR(iii,beee,eddd) cerr<<'['<<iii<<']'<<'='<<aaa[iii]<<"  "; cerr<<endl;}
bool MBE;
namespace t1_10{
    const int N=5005;
    int n,dis[N],cnt[N];
    ll d,x[N];
    vector<int> e[N];
    void sol(){
        cin>>n>>d;
        FOR(i,1,n) cin>>x[i];

        FOR(i,1,n) e[i].clear();

        FOR(i,1,n) FOR(j,1,n){
            if(llabs(x[i]-x[j])<=d){
                e[i].emplace_back(j);
            }
        }
        int ans=0;
        FOR(s,1,n){
            fill(dis+1,dis+n+1,N); fill(cnt+1,cnt+n+1,0);
            queue<int> q; q.push(s); dis[s]=0; cnt[s]=1;
            while(!q.empty()){
                int u=q.front(); q.pop();
                for(int v:e[u]){
                    if(dis[v]>dis[u]+1){
                        q.push(v);
                        dis[v]=dis[u]+1; cnt[v]=cnt[u];
                    }else if(dis[v]==dis[u]+1){
                        ++cnt[v];
                    }
                }
            }
//            outval(s);
//            outarr(dis,1,n); outarr(cnt,1,n);
            FOR(t,1,n)
                if(cnt[t]==2) ++ans;
        }
        cout<<ans/2<<endl;
    }
}
namespace t11_12{
    const int N=2e6+5;
    ll n,x[N],d,cmn,l,ans;
    void sol(){
        cin>>n>>d; ll qwq=0;
        ans=0;
        FOR(i,1,n){
            cin>>x[i];
            if(i==1) qwq=x[1];
            x[i]-=qwq;
        }
        if(n==1){
            cout<<0<<endl;
            return;
        }
        cmn=x[2]-x[1];
        l=d/cmn;
        if(l<=1){
            cout<<0<<endl;
            return;
        }
        FOR(i,1,n){
            if(i-l-(l-1)>=1) ++ans;
        }
        cout<<ans<<endl;
    }
}
namespace t13_14{
    const int N=2e6+5;
    ll n,x[N],d;
    void sol(){
        cin>>n>>d;
        FOR(i,1,n) cin>>x[i];
        ll ans=0;
        FOR(i,1,n){
            int pos=lower_bound(x+1,x+n+1,x[i]-d)-x-1;
            ans+=1LL*pos;
        }
        cout<<ans<<endl;
    }
}
bool MED;
int main(){
//    freopen("/home/csp-s-2026/migrate/migrate4.in","r",stdin);
//    freopen("in.txt","r",stdin);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int C,T; cin>>C>>T;
    if(C<=10){
        while(T--) t1_10::sol();
        return 0;
    }
    if(C<=12){
        while(T--) t11_12::sol();
        return 0;
    }
    if(C<=14){
        while(T--) t13_14::sol();
        return 0;
    }
    cerr<<fixed<<setprecision(3)<<abs(&MBE-&MED)/1048576.0<<" MB"<<endl;
    return 0;
}
//Think twice, code once!!!
//luogu uid=923403, RP++
//Oct31==Dec25?
