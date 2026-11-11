#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],ans,cntn=1073741823,maxn;
void dfs(long long i,long long cnt,long long j){
    if(i==m){
        ans=max(ans,cnt);
        return;
    }if(j==n+1)return;
    dfs(i+1,(cnt&a[j]),j+1);
    dfs(i,cnt,j+1);
    return;
}bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cntn=(cntn&a[i]);
        maxn=max(maxn,a[i]);
    }if(n<=20){
        dfs(0,1073741823,1);
        cout<<ans;
    }else if(m==1){
        cout<<maxn;
    }else if(m==n){
        cout<<cntn;
    }else if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,(a[i]&a[j]));
            }
        }cout<<ans;
    }else{
        sort(a+1,a+n+1,cmp);
        cout<<a[m];
    }
    return 0;
}
