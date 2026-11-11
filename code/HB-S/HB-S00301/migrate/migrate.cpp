# include <bits/stdc++.h>
using namespace std;
#define int long long
const int CLS=2e5+10;
int c,T,n,d,x[CLS],ans,ret,flag;
int f(int l,int r){
    int cnt=0,tot=l;
    for(int i=l+1; i<=r; i++){
        if(x[i+1]-x[tot]<=d && i+1<=r) continue;
        tot=i,cnt++;
    }
    return cnt;
}
void dfs(int dq,int s,int e,int cnt,int mn){
    if(cnt>mn) return ;
    if(flag) return ;
    if(dq==e){
        ret++;
        if(ret>2){
            flag=1;
            return ;
        }
        return ;
    }
    if(x[s+1]-x[dq]>=d && s+1<=e) dfs(dq,s+1,e,cnt,mn);
    if(x[s]-x[dq]<=d && f(s,e)+cnt+1<=d) dfs(s,s+1,e,cnt+1,mn);
    return ;
}
bool check(int l,int r,int mn){
    ret=flag=0;
    dfs(l,l+1,r,0,mn);
    //cout<<ret<<"\n";
    if(ret==2) return 1;
    return 0;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        ans=0;
        cin>>n>>d;
        for(int i=1; i<=n; i++) cin>>x[i];
        for(int i=1; i<n; i++){
            for(int j=i+1; j<=n; j++){
                int mn=f(i,j);
                if(check(i,j,mn)) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
