#include<bits/stdc++.h>
using namespace std;
long long a[2000005],st[2000005];
long long n,k;
int dfs(int x,int k1,int maxn){
    if(x==n){
        return 0;
    }
    if(k1==0){
        return maxn;
    }
    int ans=0;
    ans=dfs(x+1,k1,maxn);
    if(k==k1)ans=max(ans,dfs(x+1,k1-1,a[x]));
    else ans=max(ans,dfs(x+1,k1-1,maxn&a[x]));
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<dfs(0,k,0);
    return 0;
}
