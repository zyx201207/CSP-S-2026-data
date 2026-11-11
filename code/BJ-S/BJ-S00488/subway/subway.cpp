#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[25],t[25],ans,b[500005];
bool f[500005];
int mp[20005][20005];
void dfs(long long x,long long y,long long sum){
    if(x == y){
        ans = min(sum,ans);
        return;
    }
    f[x] = 1;
    for(int i = 1;i<=m;i++){
        if((!f[i])&&(mp[i][x])){
            dfs(i,y,sum+mp[i][x]);
        }
    }
    f[x] = 0;
}
int main(){
    freopen("r","subway.in",stdin);
    freopen("w","subway.out",stdout);
    cin>>c>>n>>m>>d>>q;
    for(long long i = 1;i<=m;i++){
        cin>>b[i];
    }
    for(long long i = 0;i<n;i++){
        int k;
        cin>>k;
        for(int j = 0;j<k;j++){
            cin>>a[j]>>t[j];
        }
        for(int j = 0;j<k;j++){
            for(int p = j+1;p<k;p++){
                mp[a[j]][a[p]] = mp[a[p]][a[j]] = t[j]+t[p];
            }
        }
    }
    while(q--){
        ans = 1000000000000000000;
        long long x,y;
        cin>>x>>y;
        dfs(x,y,0);
        cout<<ans+b[x]+b[y]<<"\n";
    }
    return 0;
}
