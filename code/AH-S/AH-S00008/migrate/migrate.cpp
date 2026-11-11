#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int c,t,n,d,a[N],mn[N],num[N];
void dfs(int x,int cnt){
    if(x>n)return ;
    if(cnt>mn[x])return ;
    if(mn[x]==cnt)num[x]++;
    else{
        num[x]=1;
        mn[x]=cnt;
    }
    for(int i=x+1;i<=n;i++){
        if(a[i]-a[x]>d)break;
        dfs(i,cnt+1);
    }

}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)mn[j]=0x3f3f3f3f,num[j]=0;
        dfs(i,0);
        for(int j=i+1;j<=n;j++){
            if(num[j]==2)ans++;
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)solve();
}
