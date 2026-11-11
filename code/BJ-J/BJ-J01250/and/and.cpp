#include<bits/stdc++.h>
using namespace std;
long long x[1000005];
bool x1[1000005];
long long cnt=INT_MIN;
long long n,m;
void dfs(long long h,long long t){
    if(h==m){
        cnt=max(cnt,t);
    }
    for(long long i=1;i<=n;i++){
        if(x1[i]==false){
            x1[i]=true;
            dfs(h+1,t&x[i]);
            x1[i]=false;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>x[i];
    }
    dfs(0,268435455);
    cout<<cnt;
    return 0;
}
