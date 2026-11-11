#include<bits/stdc++.h>
using namespace std;

#define int long long

constexpr int N=(1<<21)+7;

int n,d,C,T,a[N],X,Y,t,gk,ans;
bool f;
void dfs1(int x,int m){
    if(m>gk) return ;
    if(x==Y){
        gk=min(gk,m);
        return ;
    }
    for(int i=x;i<=n;++i){
        if(i==x) continue;
        if(abs(a[i]-a[x])<=d) dfs1(i,m+1);
    }
}
void dfs2(int x,int m){
    if(f) return ;
    if(m>gk) return ;
    if(x==Y){
        if(m==gk) ++t;
        if(t>2) f=1;
        return ;
    }
    for(int i=1;i<=n;++i){
        if(i==x) continue;
        if(abs(a[i]-a[x])<=d) dfs2(i,m+1);
    }
}
// #define LOCAL_TEST abcdg
signed main(){
    ios::sync_with_stdio(false),cin.tie(0);

    int i,j,k,l,r,x,y,z;

    #ifndef LOCAL_TEST
        freopen("subway.in","r",stdin);
        freopen("subway.out","w",stdout);
    #endif
    bool G=1;
    cin>>C>>T;
    for(;T;--T){
        cin>>n>>d;
        ans=0;
        for(i=1;i<=n;++i){
            cin>>a[i];
            if(i==2){
                l=a[i]-a[i-1];
            }if(i>2){
                if(l!=a[i]-a[i-1]) G=0;
            }
        }
        if(G){
            x=(d/l);
            if(x<=1||x>=n){
                cout<<0<<endl;
            }else{
                for(i=1;i<=n;++i){
                    ans+=max(0ll,(n-i+1)/x-1);
                }cout<<ans<<endl;
            }
        }else{
            for(i=1;i<=n;++i){
                for(j=i+1;j<=n;++j){
                    t=0,gk=4e18;
                    X=i,Y=j; f=0;
                    dfs1(i,0);
                    if(gk!=4e18){
                        dfs2(i,0);
                        if(t==2){
                            ++ans;
                        }
                    }
                }
            }cout<<ans<<endl;
        }
    }

    return 0;
}
