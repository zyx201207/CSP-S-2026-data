#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[300005],vis[300005],ans[300005];
int main(){
    freopen("card","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        int idx=i-1;
        for(int j=i;j<=n;j++){
            if(vis[a[j]]==0){
                vis[a[j]]=1;
                s[++idx]=a[j];
            }else
                while(s[idx]!=a[j]){
                    vis[idx]=0;
                    idx--;
                }
            //for(int p=i;p<=idx;p++)cout<<s[p]<<' ';
            //cout<<endl;
        }
        //cout<<"----------"<<endl;
        for(int k=1;k<=m;k++)ans[k]+=vis[k];
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
