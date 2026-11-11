#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,n,d,a[N],sum,minn=1e9;
void dfs1(long long k,long long fil,long long b){
    if(k==fil){
        minn=min(minn,b);
        return ;
    }
    for(int i=k+1;k<=fil;k++){
        if((a[i]-a[k])<=d){
            dfs1(i,fil,b+1);
        }
    }
}
void dfs2(long long k,long long fil,long long b){
    if(k==fil&&b==minn){
        sum++;
        return ;
    }
    for(int i=k+1;k<=fil;k++){
        if(a[i]-a[k]<=d){
            dfs2(i,fil,b+1);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        long long ans=0;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                sum=0;
                minn=1e9;
                dfs1(i,j,0);
                dfs2(i,j,0);
                if(sum==2){
                    //cout<<i<<' '<<j<<endl;
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
