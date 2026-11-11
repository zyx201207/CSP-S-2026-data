#include<bits/stdc++.h>
using namespace std;
queue<int> b;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int vis[300005]={0},ans[300005]={0},cnt=0;
    int n,m,a[500005]={0};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                for(int k=vis[a[j]];k<j;k++){
                    vis[b.front()]=0;
                    b.pop();
                    cnt--;
                }
            }
            b.push(a[j]);
            cnt++;
            vis[a[j]]=cnt;
        }
        for(int j=1;j<=cnt;j++){
            vis[b.front()]=0;
            ans[b.front()]++;
            b.pop();
        }
        cnt=0;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
