#include<bits/stdc++.h>
#define up(i,l,r) for(int i=(l);i<=(r);++i)
#define down(i,l,r) for(int i=(l);i>=(r);--i)
#define pi pair<int,int>
#define p1 first
#define p2 second
#define m_p make_pair
#define pb push_back
#define eb emplace_back
using namespace std;
typedef long long ll;
const int maxn=2e6+10;
int n;ll d,a[maxn];
int nxt[maxn];
int f[maxn][3][3][3];
void slv(){
    scanf("%d%lld",&n,&d);
    up(i,1,n)scanf("%lld",&a[i]);
    up(i,1,n)up(p,0,2)up(q,0,2)up(r,0,2)
        f[i][p][q][r]=0;
    int r=1;
    up(i,1,n){
        while(r<=n&&a[r]-a[i]<=d)r++;
        nxt[i]=r-1;
    }ll res=0;
    up(i,1,n){
        f[i][1][0][0]++;
        up(p,1,2)up(q,0,2)up(r,0,2)if(f[i][p][q][r]){
            ll z=f[i][p][q][r];
            if(p+q+r==2&&r&&nxt[i-2]>i)
                res+=z*1ll*(nxt[i-2]-i);
            if(p+q==2&&q&&nxt[i-1]>i)
                res+=z*1ll*(nxt[i-1]-max(nxt[i-2],i));
            if(p==2)
                res+=z*1ll*(nxt[i]-max(nxt[i-1],i));
            if(nxt[i]==i)continue;
            int np=p,nq=0,nr=0;
            if(q&&nxt[i-1]==nxt[i])np+=q;
            if(r&&nxt[i-2]==nxt[i])np+=r;
            if(nxt[i]-1>i){
                nq+=p;
                if(q&&nxt[i-1]>=nxt[i]-1)nq+=q;
                if(r&&nxt[i-2]>=nxt[i]-1)nq+=r;
            }
            if(nxt[i]-2>i){
                nr+=p;
                if(q&&nxt[i-1]>=nxt[i]-2)nr+=q;
                if(r&&nxt[i-2]>=nxt[i]-2)nr+=r;
            }
            if(np<=2){
                nq=min(nq,2),nr=min(nr,2);
                f[nxt[i]][np][nq][nr]+=z;
            }
        }
    }
    printf("%lld\n",res);
}
int main(){
    freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
    int t;for(scanf("%*d%d",&t);t--;slv());
    return 0;
}