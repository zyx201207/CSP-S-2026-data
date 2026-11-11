#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i=(a);i<=(b);i++)
#define rf(i,a,b) for(int i=(a);i>=(b);i--)
#define pt printf
#define eb emplace_back
#define LL long long
#define pii pair<int,int>
#define x first
#define y second
#define FRE(f) {auto u=freopen(f".in","r",stdin);auto v=freopen(f".out","w",stdout);}
#ifdef DB
void db(){}
void db(auto x,auto...y){cout<<x<<",";db(y...);}
#define Z(x...) {pt("\t%s = ",#x);db(x);pt("\n");}
#define ZZ(x,l,r) {pt("\t%s = ",#x);fr(IT,l,r)cout<<x[IT]<<",";pt("\n");}
#else
#define Z(...)
#define ZZ(...)
#endif
mt19937 gen(random_device{}());
int rnd(int l,int r){return gen()%(r-l+1)+l;}
#define int LL
const int N=1e6+33;
int C,T,n,d,a[N];
int soB(){
    int ans=0;
    fr(j,1,n){
        int w=a[j]-d;
        int it=lower_bound(a+1,a+n+1,w)-a;
        if(!(it+1<j))continue;
        int cnt=0;
        int l=lower_bound(a+1,a+n+1,a[it+1]-d)-a;
        int r=lower_bound(a+1,a+n+1,a[it+2]-d)-a;
        cnt+=r-l;
        // fr(i,1,n){
        //     if(a[it+1]<=a[i]+d && a[it+2] > a[i]+d){
        //         cnt++;
        //     }
        // }
        ans+=cnt;

    }
    return ans;
}
int soA(){
    int dd=d/(a[2]-a[1]);
    if(dd==0)return 0;
    if(dd==1)return 0;
    int ans=n-2*dd+1;
    if(ans<0)return 0;
    return ans;
}
bool aa(int i,int j){
    return abs(a[i]-a[j])<=d;
}
int al[N],ar[N];
int bfs(int s){
    static int q[N],hd,tl,d[N],cnt[N];
    hd=0,tl=-1;
    fr(i,1,n)d[i]=n+1,cnt[i]=0;
    d[s]=0;
    q[++tl]=s;
    cnt[s]=1;
    while(hd<=tl){
        int u=q[hd++];

        fr(v,al[u],ar[u]){
            if(d[v]>n){
                cnt[v]=cnt[u];
                d[v]=d[u]+1;
                q[++tl]=v;
            }else if(d[v]==d[u]+1){
                cnt[v]+=cnt[u];
            }
        }
    }
    return count(cnt+1,cnt+n+1,2);
}
int soBF(){
    fr(i,1,n){
        al[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
        ar[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
    }
    int ans=0;
    fr(i,1,n){
        int ret=bfs(i);
        ans+=ret;
    };
    assert(ans%2==0);
    ans/=2;
    return ans;
}
signed main(){
    FRE("migrate");
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>C>>T;
    while(T--){
        int ans=0;
        cin>>n>>d;
        fr(i,1,n)cin>>a[i];
        // ans=soA();
        if(C==13||C==14){
            ans=soB();
        }else if(C==11||C==12){
            ans=soA();
        }else{
            ans=soBF();
        }
        pt("%lld\n",ans);
    }
    return 0;
}