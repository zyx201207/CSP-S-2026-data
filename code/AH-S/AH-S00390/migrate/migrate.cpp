#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,a[2000005],n,d,ans[200005],y,mn=0x3f3f3f3f3f3f3f3f;
void dfs(int step,int cnt){
    if(step==n+1){
        ans[++y]=cnt;
        mn=min(mn,cnt);
        return ;
    }
    dfs(step+1,cnt);
    for(int i=1,j=1;a[j]<=a[step]+i&&i<=d;i++,j++){
        dfs(step+1,cnt+1);
    }
}
signed main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>c>>t;
while(t--){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1,0);
    int z=0;
    for(int i=1;i<=y;i++){
        if(mn==ans[i]) z++;
    }
    cout<<z<<"\n";
}
return 0;
}
