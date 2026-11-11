#include<bits/stdc++.h>
#define int long long
#define For(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
const int N=5e5+10,inf=1e18;
int c,t,n,d,ans,pos,x[N],cnt[N],dis[N];
vector<int> g[N];
bitset<N> vis;
void bfs(int st){
    queue<int> q;
    For(i,1,n) cnt[i]=0,dis[i]=inf;
    dis[st]=0,cnt[st]=1;
    q.push(st);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        For(i,0,(int)(g[u].size()-1)){
            int v=g[u][i];
            if(dis[u]+1>=dis[v]){
                if(dis[u]+1==dis[v]) cnt[v]+=cnt[u];
                continue;
            }
            q.push(v);
            dis[v]=dis[u]+1,cnt[v]=cnt[u];
        }
    }
    For(i,1,n){
        if(cnt[i]==2) ans++,cerr<<st<<' '<<i<<'\n';
    }
}
bool check(int l,int r){
    return abs(x[l]-x[r])<=d;
}
bool check2(int x,int p){
    return (check(x,pos+1*p)+check(x,pos+2*p))==1;
}
bool check3(int x,int p){
    return (check(x,pos+1*p)+check(x,pos+2*p))==0;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==13||c==14){
        while(t--){
            cin>>n>>d;
            For(i,1,n) cin>>x[i];
            sort(x+1,x+n+1);
            pos=0;
            For(i,1,n){
                if(check(i,1)&&check(i,n)){
                    pos=i;
                    break;
                }
            }
            int l=1,r=n,L=1,R=n;
            while(check3(L+1,1)) L++;
            l=L;
            while(check2(l+1,1)) l++;
            while(check3(R-1,-1)) R--;
            r=R;
            while(check2(r-1,-1)) r--;
            cout<<L*(R-r)+(n-R+1)*(l-L)<<'\n';
        }
        return 0;
    }
    while(t--){
        cin>>n>>d;
        For(i,1,n) cin>>x[i];
        For(i,1,n) g[i].clear();
        ans=0;
        For(i,1,n){
            For(j,i+1,n){
                if(abs(x[i]-x[j])<=d){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        For(i,1,n) bfs(i);
        cout<<ans/2<<'\n';
    }
    return 0;
}