#include<iostream>
#include<cstring>
using namespace std;
int c,t,n,d,xi[5005],cnt[5005];
int dfs(int x,int now ,int dep){
    if(x==n)return 1;
    if(now>dep)return 0;
    for(int i=x+1;i<=n;i++){
        if(xi[i]-xi[x]<=d)cnt[x]+=dfs(i,now+1,dep);
        else break;
    }
    return cnt[x];
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","W",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>xi[i];
        for(int i=1;i;i++)if(dfs(1,0,i))break;
        cout<<(cnt[1]/2)<<'\n';
        memset(cnt,0,sizeof(cnt));
    }
    return 0;
}
