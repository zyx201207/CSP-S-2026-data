#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
int vis[300005];
stack<int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int now=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(vis[a[j]]==0){
                q.push(a[j]);
                vis[a[j]]++;
            }
            else{
                while(!q.empty()){
                    now=q.top();
                    //cout<<now<<" ";
                    q.pop();
                    vis[now]--;
                    if(now==a[j])break;
                }
                vis[a[j]]++;
                q.push(a[j]);
            }
        }
        while(!q.empty()){
            now=q.top();
            //cout<<now<<" ";
            q.pop();
            vis[now]--;
            ans[now]++;
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++)printf("%d ",ans[i]);
    return 0;
}
