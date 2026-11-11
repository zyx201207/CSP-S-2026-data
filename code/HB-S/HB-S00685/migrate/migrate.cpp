#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+10;
int c,T;
ll n,d,x[maxn];
ll dis[maxn],sum[maxn];
void dfs(int pos,int cnt,int to){
    for(int i=pos+1;i<=n;i++){
        if(i==to){
            if(x[i]-x[pos]>d) break;
            if(cnt+1<dis[to]){
                dis[to]=cnt+1;
                sum[to]=1;
            }
            else if(cnt+1==dis[to]){
                sum[to]++;
            }
            break;
        }
        if(x[i]-x[pos]<=d) dfs(i,cnt+1,to);
        else break;
        
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        if(c==11||c==12){
            ll cha=x[2]-x[1];
            ll stp=d/cha;
            if(stp==1||stp==0){
                cout<<0<<'\n';
                continue;
            }
            ll ans=n-2*stp+1;
            if(ans<=0) cout<<0<<'\n';
            else cout<<ans<<'\n';
            continue;
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]<=d) continue;
                dis[j]=1e18,sum[j]=0;
                dfs(i,0,j);
                if(sum[j]==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}