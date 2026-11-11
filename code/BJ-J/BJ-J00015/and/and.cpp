#include<bits/stdc++.h>
using namespace std;
long long n,m;long long a[200010];
long long dfs(long long sum,long long x,int xb,long long dt){
    sum=sum&x;
    if(dt==m){
        return sum;
    }long long re=0;
    for(int i=xb+1;i<n-+1;i++){
        re=max(re,dfs(sum,a[i],i,dt+1));
    }
    return re;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long ans=0;
    for(int i=0;i<=n-m;i++){
        ans=max(ans,dfs(a[i],a[i],i,1));
    }
    cout<<ans;
    return 0;
}