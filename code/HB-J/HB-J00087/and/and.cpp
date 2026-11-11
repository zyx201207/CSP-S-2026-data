#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2*1e5+10;
int n,m;
int a[N],b[N],res[N],mx;
long long ans,cnt;
void dfs(int x,int sum,int pre){
    if(n-pre<m-x)return ;
    if(x>m){
        ans=max(ans,sum);
        return ;
    }
    for(int i=pre;i<=n;i++){
        res[x]=a[i];
        if(x==1)sum=a[i];
        dfs(x+1,(sum&a[i]),i+1);

    }
}
signed main(){
    freopen("ans.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1)cnt=a[i];
        mx=max(a[i],mx);
        (cnt&=a[i]);
    }
    if(m==1){
        cout<<mx;
    }
    else if(m==n){
        cout<<cnt;
    }
    else {
        dfs(1,0,1);
        cout<<ans;
    }
    return 0;
}
