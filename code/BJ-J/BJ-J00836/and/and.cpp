#include <bits/stdc++.h>
#define N int(2e5+10)
using namespace std;
typedef long long ll;
ll m,n,ans=-1e18,maxn=-1e18;
ll a[N];
bool visited[N];
void dfs(ll k,ll s){
    if(k==m+1){
        ans=max(ans,s);
        return ;
    }
    for(int i=1;i<=n;++i)
        if(!visited[i]){
            if(k==1){
                visited[i]=1;
                dfs(k+1,a[i]);
                visited[i]=0;
            }else{
                visited[i]=1;
                ll temp=s;
                temp&=a[i];
                dfs(k+1,temp);
                visited[i]=0;
            }
        }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    if(m==n){
        ll A=a[1];
        for(int i=2;i<=n;++i) A&=a[i];
        cout<<A;
        return 0;
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
