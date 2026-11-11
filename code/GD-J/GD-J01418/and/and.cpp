#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
//#define int LL
#define For(i,t,n) for(int i=t;i<=n;++i)
#define foR(i,t,n) for(int i=t;i>=n;--i)
#define isdigit(c) (c>=48&&c<=57)
#define gc getchar
void read(int& x){
    x=0;int c=gc(),f=1;
    while(!isdigit(c)){if(c=='-')f=-1;c=gc();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=gc();}
    x*=f;
}
void write(int x){
    int stk[128],top=0;
    if(x<0) putchar('-'),x=-x;
    do{stk[++top]=x%10;x/=10;}while(x);
    while(top)putchar(stk[top--]|48);
}

const int MAXN=2e5+5;
const int MAXV=(1<<30)+5;

int n,m;
int a[MAXN];
vector<int> v[40];
// vector<int> now,vis;
int now[MAXN],len;
int vis[MAXN], vl;
int t[MAXN];

void merge(int p){
    // cerr << "merge " << p << '\n';
    // if(now.empty()){
    //     now = v[p];
    //     return;
    // }
    if(!len){
        for(int x:v[p])
            now[++len] = x;
        return;
    }
    For(i, 1, len) vis[i] = now[i];
    vl = len;
    For(i, 1, vl) t[vis[i]]++;
    int cnt = 0;
    for(int x:v[p]){
        if(t[x])
            ++cnt;
    }
    // cerr << "cnt=" << cnt << '\n';
    // cerr << "now.size()=" << now.size() << " now.empty()=" << now.empty() << '\n';
    if(cnt>=m){
        // now.clear();
        len = 0;
        for(int x:v[p]){
            if(t[x])
                // now.push_back(x);
                now[++len] = x;
        }
    }
    For(i, 1, vl) t[vis[i]]--;
    // for(int x:vis)
    //     t[x]--;
    // cerr << "now: ";
    // for(int x:now)
    //     cerr << x << ' ';
    // cerr << '\n';
}

void solve(){
    read(n); read(m);
    For(i,1,n) read(a[i]);
    For(i,1,n){
        foR(j,30,0){
            if((a[i]&(1<<j))){
                v[j].push_back(i);
            }
        }
    }
    foR(i,30,0){
        if(v[i].size()>=m){
            merge(i);
        }
    }
    if(len<m){
        write(0);
    }else{
        int ans = (1 << 30) - 1;
        For(i,1,m) ans &= a[now[i]];
        write(ans);
    }
}

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    // freopen("and.err", "w", stderr);
    solve();
    return 0;
}
