#include<bits/stdc++.h>
using namespace std;
#define fst first
#define scd second
#define rep(i,s,t) for(int i=s;i<=t;++i)
#define dep(i,s,t) for(int i=s;i>=t;--i)
#define endl '\n'
#define pb push_back
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

const int N=2e6+10;

ll a[N];
int pre[N],nxt[N];
string tos(int x){
    string s="";
    if(x<9) return s+(char)(x+'0');
    return tos(x/10)+(char)(x%10+'0');
}
void __solve(){
    ll d;
    int n;cin>>n>>d;
    rep(i,1,n) cin>>a[i];
    pre[1]=1;
    rep(i,2,n){
        pre[i]=pre[i-1];
        while(pre[i]<i&&a[i]-a[pre[i]]>d) ++pre[i];
    }
    nxt[n]=n;
    dep(i,n-1,1){
        nxt[i]=nxt[i+1];
        while(nxt[i]>i&&a[nxt[i]]-a[i]>d) --nxt[i];
    }
    map<string,int> mp;
    auto ins2=[&](vector<int> t){
        sort(t.begin(),t.end());
        string s="";
        for(int i:t){
            s+=tos(i);
            s+='#';
        }
        // cerr<<s<<endl;
        mp[s]++;
    };
    auto ins=[&](vector<int> t,int mx){
        rep(i,0,t.size()-1){
            if(t[i]==mx-1) continue;
            t[i]++;
            ins2(t);
            t[i]--;
        }
    };
    dep(i,n,1){
        int p=pre[i];
        if(p==i) continue;
        vector<int> v;
        while(p!=1){
            v.pb(p);
            ins(v,i);
            p=pre[p];
            if(p==pre[p]) break;
        }
    }
    ll ans=0;
    auto chk=[&](vector<int> v){
        if(v.empty()) return;
        string s="";
        for(int i:v){
            s+=tos(i);
            s+='#';
        }
        // cerr<<s<<' '<<mp[s]<<endl;
        ans+=mp[s];
    };
    rep(i,1,n){
        int p=nxt[i];
        vector<int> v;
        while(p!=n){
            v.pb(p);
            chk(v);
            p=nxt[p];
            if(p==nxt[p]) break;
        }
    }
    // cerr<<endl;
    // for(auto [u,v]:mp) cerr<<u<<' '<<v<<endl;
    cout<<ans<<endl;
}
int main(){
#ifndef DEBUG
    file(migrate)
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,t=1;
    cin>>c>>t;
    while(t--) __solve();
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
#define fst first
#define scd second
#define rep(i,s,t) for(int i=s;i<=t;++i)
#define dep(i,s,t) for(int i=s;i>=t;--i)
#define endl '\n'
#define pb push_back
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

const int N=2e6+10;

ll a[N],f[N][2];
int pre[N],nxt[N],cpre[N],cpre2[N];
void __solve(){
    int n;ll d;
    cin>>n>>d;
    rep(i,1,n) cin>>a[i];
    rep(i,1,n) cpre[i]=cpre2[i]=f[i][0]=f[i][1]=0;
    pre[1]=1;
    rep(i,2,n){
        pre[i]=pre[i-1];
        while(pre[i]<i&&a[i]-a[pre[i]]>d) ++pre[i];
    }
    nxt[n]=n;
    dep(i,n-1,1){
        nxt[i]=nxt[i+1];
        while(nxt[i]>i&&a[nxt[i]]-a[i]>d) --nxt[i];
    }
    // rep(i,1,n) cerr<<pre[i]<<' ';
    // cerr<<endl;
    // rep(i,1,n) cerr<<nxt[i]<<' ';
    // cerr<<endl;
    rep(i,1,n){
        ++cpre[pre[i]];
        if(pre[pre[i]]==pre[pre[i]+1]) ++cpre2[pre[i]];
    }
    dep(i,n,1){
        if(nxt[i]==i) continue;
        if(pre[nxt[i]]<i-1||pre[pre[nxt[i]]]!=pre[i]) continue;
        if(pre[nxt[i]]==i-1) f[i][1]=f[nxt[i]][0];
        else{
            f[i][0]=f[nxt[i]][0];
            f[i][1]=f[nxt[i]][1];
        }
        // cerr<<f[i][0]<<' '<<f[i][1]<<endl;
        f[i][0]+=cpre[i];
        f[i][1]+=cpre2[i-1];
        // cerr<<f[i][0]<<' '<<f[i][1]<<endl<<endl;
    }
    rep(i,1,n) cerr<<f[i][0]<<' '<<f[i][1]<<endl;
    ll ans=0;
    rep(i,1,n){
        if(pre[pre[nxt[i]]]!=pre[i]&&pre[nxt[i]]==i-1){
            ans+=f[nxt[i]][0];
            
        ans+=f[nxt[i]][1];
        if(nxt[i]!=i&&nxt[i]!=i+1) ans+=cpre[nxt[i]-1]-cpre2[nxt[i]-1];
        cerr<<ans<<endl;
        if(nxt[i]==i+1&&nxt[i+1]!=i+1) ans-=cpre2[i];
    }
    cout<<ans<<endl;
}
int main(){
#ifndef DEBUG
    file(migrate)
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,t=1;
    cin>>c>>t;
    while(t--) __solve();
    return 0;
}
*/