#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,d,a[N],ans,minx,cnt;
void dfs(int pos,int ed,int step,int&minx){
    if(pos==ed){
        minx=min(minx,step);
        return;
    }
    for(int i=1;i<=d;i++){
        if(pos+i>ed)
            return;
        dfs(pos+i,ed,step+1,minx);
    }
}
void cntmin(int pos,int ed,int step,int minx,int&cnt){
    if(pos==ed){
        if(step==minx)
            cnt++;
        return;
    }
    for(int i=1;i<=d;i++){
        if(pos+i>ed)
            return;
        cntmin(pos+i,ed,step+1,minx,cnt);
    }
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            int minx=1e9,cnt=0;
            dfs(a[i],a[j],0,minx);
            cntmin(i,j,0,minx,cnt);
            if(cnt==2)
                ans++;
        }
    cout<<ans<<endl;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
        solve();
    return 0;
}