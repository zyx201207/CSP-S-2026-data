#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],x[1000005],pos=0,vis[300005],vi[300005];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
            cin>>a[i],vis[a[i]]++;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++)
            if(vis[a[j]]>0&&vi[a[j]]==0) ans[a[j]]++,vi[a[j]]=1;
        vis[a[i]]--;
        memset(vi,0,sizeof(vi));
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
    return 0;
}