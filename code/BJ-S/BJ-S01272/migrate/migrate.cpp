#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
template<typename T>
void chkmin(T &x,const T &y){x=min(x,y);}
template<typename T>
void chkmax(T &x,const T &y){x=max(x,y);}
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3f;
const int MOD=998244353;
void add(int &x,int y){
    x+=y;
    if(x>=MOD) x-=MOD;
}
int add2(int x,int y){
    add(x,y);
    return x;
}
int qpow(int a,ll b){
    int mul=1;
    for(;b;b>>=1,a=(ll)a*a%MOD) if(b&1) mul=(ll)mul*a%MOD;
    return mul;
}
const int N=2000005;
int n;
ll d,x[N];
struct Tag{
    int lst2,cnt,s;
};
vector<Tag> vec[N];
int nxt(int p){return upper_bound(x+p,x+n+1,x[p]+d)-x-1;}
void __INIT__(){}
void __SOLVE__(){
    scanf("%d%lld",&n,&d);
    for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
    for(int i=1;i<=n;i++) vec[i].clear();
    ll ans=0;
    for(int i=1;i<=n;i++){
        int lst=i,lst2=-1;
        int cnt=0;
        for(int t=1;t<=2&&lst<n;t++){
            int j=nxt(lst);
            if(j==lst||cnt>=2) break;
            if(!cnt&&lst-1>=i&&(lst2-1<i||x[lst-1]-x[lst2-1]>d)){
                int l=lst,r=nxt(lst-1);
                if(lst-2>=i) chkmax(l,nxt(lst-2));
                // printf("%d %d %d (%d,%d]\n",i,lst2,lst,l,r);
                ans+=(r-l);
            }
            if(cnt==1){
                int l=lst,r=j;
                if(lst-1>=i) chkmax(l,nxt(lst-1));
                // printf("%d %d %d (%d,%d]\n",i,lst2,lst,l,r);
                ans+=(r-l);
            }
            if(lst-1>=i&&x[j]-x[lst-1]<=d){
                cnt++;
                if(lst2-1>=i&&x[lst-1]-x[lst2-1]<=d) cnt++;
                if(lst-2>=i&&x[j]-x[lst-2]<=d) cnt++;
            }
            lst2=lst,lst=j;
            if(t==2&&cnt<2) vec[lst].push_back({lst2,cnt,1});
        }
    }
    for(int lst=1;lst<=n;lst++){
        int j=nxt(lst);
        if(j==lst) continue;
        int sum[2]={0,0};
        for(auto [lst2,cnt,s]:vec[lst]){
            if(!cnt&&x[lst-1]-x[lst2-1]>d){
                int l=max(lst,nxt(lst-2)),r=nxt(lst-1);
                ans+=(ll)s*(r-l);
            }
            if(cnt==1){
                int l=max(lst,nxt(lst-1)),r=j;
                ans+=(ll)s*(r-l);
            }
            if(x[j]-x[lst-1]<=d){
                cnt++;
                if(x[lst-1]-x[lst2-1]<=d) cnt++;
                if(x[j]-x[lst-2]<=d) cnt++;
            }
            if(cnt<2) sum[cnt]+=s;
        }
        vec[j].push_back({lst,0,sum[0]});
        vec[j].push_back({lst,1,sum[1]});
    }
    printf("%lld\n",ans);
}
int main(){
    #ifndef JZQ
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    #endif
    int T=1;
    scanf("%*d%d",&T);
    __INIT__();
    while(T--) __SOLVE__();
    return 0;
}