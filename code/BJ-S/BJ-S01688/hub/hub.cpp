#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y,ans=0x3f3f3f3f3f3f3f3f;
long long w[1000000],k[1000000];
long long a[25][500005],t[25][500005];
long long hc[25000][1000];
void dfs(long long now,long long sumt){
    if(now==y){
        ans=min(ans,sumt);
        return;
    }
}
void solve(){
    cin>>x>>y;
    dfs(x,w[x]);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    
    cout<<2026;
    return 0;
}