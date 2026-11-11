#include <iostream>
#include <cstdlib>
#define int long long
using namespace std;

const int N=2000005;

int x[N];
int pre[N],nxt[N];
int f[N],g[N];

struct node{
    int val,cnt;
    node operator+(const node& b){
        if(val<b.val) return *this;
        else if(val>b.val) return b;
        return node({val,min(5ll,cnt+b.cnt)});
    }
} dp[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    //freopen("migrate/migrate4.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;++i){
            cin>>x[i];
        }pre[0]=nxt[0]=0;
        for(int i=1;i<=n;++i){
            if(i==1) pre[i]=nxt[i]=1;
            else pre[i]=pre[i-1],nxt[i]=nxt[i-1];
            while(x[i]-x[pre[i]]>d){
                ++pre[i];
            }while(nxt[i]<=n && x[nxt[i]]-x[i]<=d){
                ++nxt[i];
            }--nxt[i];
            //cout<<pre[i]<<' ';
        }//cout<<'\n';
        if(c<=10){
            int ans=0;
            for(int s=1;s<=n;++s){
                dp[s]=node({0,1});
                for(int i=s+1;i<=n;++i){
                    int cp=max(pre[i],s);
                    if(cp==i) break;
                    dp[i]=dp[cp];
                    if(cp+1<i) dp[i]=dp[i]+dp[cp+1];
                    if(cp+2<i) dp[i]=dp[i]+dp[cp+2];
                    dp[i].val+=1;
                    ans+=(dp[i].cnt==2);
                    //if(dp[i].cnt==2)
                        //cout<<"-----> "<<s<<" "<<i<<' '<<dp[i].val<<endl;
                }
            }cout<<ans<<'\n';
        }else{
            for(int i=1;i<=n;++i){
                if(pre[i]==i || pre[pre[i]]==pre[pre[i]+1]){
                    f[i]=i-pre[i]+1;
                }else{
                    f[i]=f[pre[i]]+i-pre[i]-(pre[i]-pre[pre[i]+1]);
                }
            }for(int i=n;i>=1;--i){
                if(nxt[i]==i || nxt[nxt[i]]==nxt[nxt[i]-1]){
                    g[i]=nxt[i]-i+1;
                }else{
                    g[i]=g[nxt[i]]+nxt[i]-i-(nxt[nxt[i]-1]-nxt[i]);
                }
            }
            //for(int i=1;i<=n;++i) cout<<pre[i]<<' ';cout<<'\n';
            //for(int i=1;i<=n;++i) cout<<nxt[i]<<' ';cout<<'\n';

            int ans=0;
            for(int i=1;i<=n;++i){
                if(nxt[i]!=i && nxt[nxt[i]]!=nxt[i]
                   && nxt[nxt[i]-1]==nxt[nxt[i]] && nxt[nxt[i]-2]!=nxt[nxt[i]]){
                        ans+=(f[i]-(i-pre[i]+1))*(g[nxt[nxt[i]]]-(nxt[nxt[nxt[i]]]-nxt[nxt[i]]+1));
                        //cout<<"---> "<<i<<' '<<nxt[nxt[i]]<<" | "
                        //    <<f[i]<<' '<<g[nxt[nxt[i]]]<<'\n';
                   }
                if(nxt[i]!=i){
                    if(nxt[i]!=i+1){
                        ans+=nxt[nxt[i]-1]-nxt[nxt[i]-2];
                    }
                }
            }cout<<ans<<'\n';
        }
    }
    return 0;
}
