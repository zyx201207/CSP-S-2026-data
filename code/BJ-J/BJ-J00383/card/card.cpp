#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int res[500005],cnt[500005];
bool vis[500005];
queue<int>q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        res[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        bool flag=false;
        memset(vis,false,sizeof vis);
        for(int r=1;r<=n;r++){
            cnt[a[r]]++;
        }
        for(int r=i;r<=n;r++
                cnt[k]--;){
            for(int j=r-1;j>=i;j--){
                q.push(a[j]);
                cnt[a[j]]--;
                if(a[j]==a[r]){
                    flag=true;
                    break;
                }
            }
            if(!flag){
                while(!q.empty()){
                    q.pop();
                }
            }
        }
        while(!q.empty()&&flag){
            int k=q.front();
            q.pop();
            if(!vis[k]&&cnt[k]==0){
                res[k]--;
                vis[k]=true;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<res[i]<<' ';
    }
    cout<<endl;
    return 0;
}