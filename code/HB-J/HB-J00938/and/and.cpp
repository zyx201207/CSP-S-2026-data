#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
//int path[maxn];
int n,m,a[maxn],ans=-1;
void dfs(int now,int c,int sum){
    for(int i=now;i<=n;i++){
        if(c!=m){
            //path[c]=a[now];
            dfs(now+1,c+1,sum&a[now]);
            //path[c]=0;
        }
        if(now+m-c<=n) dfs(now+1,c,sum);
    }
    //for(int i=0;i<m;i++) cout<<path[i]<<" ";
    //cout<<sum<<endl;
    if(c==m){
        ans=max(ans,sum);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0xffffffff);
    cout<<ans;
    return 0;
}
