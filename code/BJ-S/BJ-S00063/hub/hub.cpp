#include<bits/stdc++.h>
#define int long long
using namespace std;
int db;
int c,T,n,d,a[2000005],dp[2000005],as;
signed lt[2000005],rt[2000005];
vector<signed> p;
void init(){
    p.clear();
}
int dfs(int x,int r,int st){
    if(x==r){
        if(st==dp[r])return 1;
        return 0;
    }
    int sum=0;
    for(int j=x+1;j<=r;j++){
        sum+=dfs(j,r,st+1);
    }
    return sum;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    db=0;
    if(db==0){
        freopen("hub.in","r",stdin);
        freopen("hub.out","w",stdout);
    }
    cin>>c>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
        }
        if(n&1){
            cout<<(int)ceil((n-1)*1.0/4.0)<<endl;
        }else{
            cout<<(int)ceil(1.0*(n-1)/4.0)<<endl;
        }
    }
    return 0;
}