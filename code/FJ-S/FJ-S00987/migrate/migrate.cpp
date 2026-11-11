#include<bits/stdc++.h>
#define forto(i,a,b) for(int i(a),_##i(b);i<=_##i;i++)
#define forbk(i,a,b) for(int i(a),_##i(b);i>=_##i;i--)
#define forv(i,a) for(int i(0),_##i(a);i<_##i;i++)
#define il inline
#define ll long long
using namespace std;

const int N=2000005;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,far[N];
ll d,a[N];
int fa[N],w[N],t[N][2];
vector<int>ch[N];

int cL,cR;
il void count_reset(){
    cL=1,cR=0;
}
il int count(ll l,ll r){
    if(l>r)return 0;
    while(cR<n&&a[cR+1]<=r)cR++;
    while(a[cL]<l)cL++;
    return cR-cL+1;
}

int sw[N];ll st[N][2],ans;
il void dfs(int x,int n1,int n2){
    // cerr<<x<<'\n';
    sw[x]++,st[x][0]+=t[x][0],st[x][1]+=t[x][1];
    if(w[x]>=2)n1=n2=x;
    else if(w[x]==1)n2=n1,n1=x;
    int bg=fa[fa[n1]],ed=fa[fa[n2]];
    // cerr<<x<<','<<bg<<','<<ed<<' '<<;
    ans+=sw[bg]-sw[ed];
    ans+=st[bg][0]-st[ed][0];
    ans+=st[x][1]-st[bg][1];
    for(int y:ch[x])sw[y]=sw[x],st[y][0]=st[x][0],st[y][1]=st[x][1],dfs(y,n1,n2);
}

il void work(){
    // cin>>n>>d;
    forto(i,1,n)cin>>a[i];
    int curfar=1;
    forto(i,1,n){
        while(curfar<n&&a[curfar+1]-a[i]<=d)curfar++;
        if(curfar!=i)fa[i]=curfar,ch[curfar].emplace_back(i);
        far[i]=curfar;
    }

    count_reset();
    forto(i,1,n){
        if(!fa[i]||!fa[fa[i]])continue;
        w[i]=count(max(a[i]+1,a[fa[fa[i]]]-d),a[fa[i]]-1);
    }

    forto(i,1,n){
        if(!fa[i]||!fa[fa[i]])continue;
        int f1,f2;
        if(i==fa[i]-1)f1=f2=-1;
        else if(i==fa[i]-2)f1=fa[i]-1,f2=-1;
        else f1=fa[i]-1,f2=fa[i]-2;
        int d1;
        if(f2==-1)d1=fa[i];
        else d1=max(fa[i],far[f2]);
        int d2;
        if(f1==-1)d2=fa[i];
        else d2=max(fa[i],far[f1]);
        d1=min(d1+1,fa[fa[i]]),d2=min(d2+1,fa[fa[i]]);
        // cerr<<i<<": "<<d1<<' '<<d2<<'\n';
        t[i][0]=fa[fa[i]]-d2,t[i][1]=d2-d1;
    }

    // forto(i,1,n)cerr<<fa[i]<<' '<<w[i]<<' '<<t[i][0]<<' '<<t[i][1]<<' '<<far[i]<<'\n';

    ans=0;
    forto(i,1,n)if(!fa[i])dfs(i,0,0);
    cout<<ans<<'\n';

    forto(i,1,n){
        fa[i]=w[i]=t[i][0]=t[i][1]=far[i]=0;
        sw[i]=st[i][0]=st[i][1]=0;
        vector<int>().swap(ch[i]);
    }
}

namespace force{
    int dist,mn,cnt;
    il void dfs(int x,int step){
        if(x==dist){
            if(step<mn)mn=step,cnt=1;
            else if(step==mn)cnt++;
            return;
        }
        forto(i,x+1,dist){
            if(a[i]-a[x]>d)break;
            dfs(i,step+1);
        }
    }
    il void work(){
        // cerr<<"force\n";
        // cin>>n>>d;
        forto(i,1,n)cin>>a[i];
        int ans=0;
        forto(i,1,n)forto(j,i+1,n){
            dist=j,mn=0x3f3f3f3f,cnt=0;
            dfs(i,0);
            if(cnt==2)ans++;
        }
        cout<<ans<<'\n';
    }
}

signed main(){
    freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int c,t;cin>>c>>t;
    int fc=0;
    while(t--){
        cin>>n>>d;
        if(c==1||c==2||(n<=9&&fc<=100))force::work(),fc++;
        else work();
    }
    return 0;
}