#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Ror(i,a,b) for(int i=(a);i>=(b);i--)
#define pll pair<ll,ll>
using namespace std;using ll=long long;
const int N=2e6+10;
int c,t,n,d,ord[N];ll a[N],ans;
vector<pll>seg;vector<ll>q,ql;
ll kep[N],pas[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    For(i,1,N)ord[i]=i;
    while(t--){
        q.clear(),ql.clear(),seg.clear();
        q.push_back(0);
        ql.push_back(0);
        seg.push_back({0,0});
        ans=0;
        memset(a,0,sizeof(a));
        memset(kep,0,sizeof(kep));
        memset(pas,0,sizeof(pas));
        int n;ll d;scanf("%d%d",&n,&d);
        For(i,1,n)scanf("%lld",a[i]);
        ll l=1,sum=0;
        For(r,1,n){
            sum+=a[r];
            while(sum>d)seg.push_back({l,r-1}),sum-=a[l],l++;
        }//here to discrete(li san hua) seg's l,r
        For(i,l,n)seg.push_back({i,n});
        for(auto[l,r]:seg)q.push_back(r);
        Ror(i,n,1){
            auto [l,r]=seg[i];//l=i+1
            int x=lower_bound(ord+i+1,ord+n+1,r)-ord;
            if(!x||x>n)continue;
            while(r-x+1<1)x--;
            while(r-x+1==1)kep[l]+=kep[x]+1,pas[l]+=pas[x],x--;
            while(r-x+1==2)pas[l]+=kep[x]+1,x--;
        }
        For(i,1,n)ans+=pas[i];
        printf("%lld\n",ans);
    }
    return 0;
}
