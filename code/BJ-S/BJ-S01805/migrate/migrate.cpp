#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e6+10;
ll minn=1e9,ans,c,T,n,d,a[maxn];
void dfs(ll st,ll end,ll last,ll now,ll cnt){
    if((a[now]-a[last])>d) return ;
    if(now==end){
        if(cnt==minn) ans++;
        if(cnt<minn){
            minn=cnt;ans=1;
        }
        return ;
    }
    if((a[now+1]-a[last])<=d){
        dfs(st,end,last,now+1,cnt);
    }
    dfs(st,end,now,now+1,cnt+1);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){
        ll sum=0;bool flag=1;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        ll k=a[2]-a[1];
        for(int i=2;i<=n;i++){
            if(a[i]-a[i-1]!=k){ flag=0; break; }
        }
        if(!flag){
            dfs(1,5,1,1,0);
            for(int i=1;i<=n;i++){
                for(int j=i+2;j<=n;j++){
                    if((a[j]-a[j-1])>d) continue;
                    minn=1e9,ans=0;
                    dfs(i,j,i,i,0);
                    if(ans==2){
                        // cout<<i<<" "<<j<<endl;
                        sum++;
                    }
                }
            }
            cout<<sum<<'\n';
            continue;
        }
        if(flag){
            if(d>=2*k && d<k*3) sum=n-3;
            if(d<2*k) sum=0;
            if(d>=3*k) sum=n-2*d/k+1;
            cout<<max(0ll,sum)<<'\n';
            continue;
        }
        
    }
    return 0;   
}