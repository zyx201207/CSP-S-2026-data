#include<bits/stdc++.h>
using namespace std;
struct station{
    long long t,id;
};
vector<station> st[500005];
long long c,n,m,d,q;
long long w[500005];
long long k[505];
long long change[505][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld",&c);
    scanf("%lld",&n);
    scanf("%lld",&m);
    scanf("%lld",&d);
    scanf("%lld",&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&k[i]);
        for(int j=0;j<k[i];j++){
            long long x,y;
            scanf("%lld",&x);
            scanf("%lld",&y);
            st[x].push_back({y,i});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            change[i][j]=LLONG_MAX;
        }
        change[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(station v:st[i]){
            for(station u:st[i]){
                if(v.id==u.id) continue;
                if(change[v.id][u.id]==LLONG_MAX){
                    change[v.id][u.id]=v.t+u.t;
                }
                change[v.id][u.id]=min(change[v.id][u.id],v.t+u.t);
                change[u.id][v.id]=change[v.id][u.id];
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(change[i][k]==LLONG_MAX||change[k][j]==LLONG_MAX) continue;
                change[i][j]=min(change[i][j],change[i][k]+change[k][j]);
                change[j][i]=change[i][j];
            }
        }
    }
    while(q--){
        long long x,y;
        cin>>x>>y;
        long long ans=LLONG_MAX;
        for(station v:st[x]){
            for(station u:st[y]){
                long long sum=v.t+u.t+change[v.id][u.id];
                ans=min(ans,sum);
            }
        }
        ans+=(w[x]+w[y]);
        printf("%lld\n",ans);
    }
    return 0;
}
