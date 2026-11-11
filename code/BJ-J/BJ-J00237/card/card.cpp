#include<iostream>
#include<cstring>
using namespace std;
const int N=5e5+1;
int n,m,a[N];
int p[N],ans[N];
bool vis[N],no[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=i;j>=1;j--){
            if(a[i]==a[j]){
                p[i]=j;
            }
            break;
        }
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        memset(no,0,sizeof(no));
        for(int j=i;j<=n;j++){
            if(vis[a[j]]&&no[j]==0){
                for(int k=p[j];k<j;k++){
                    no[k]=1;
                    vis[a[k]]=0;
                }
            }
            vis[j]=1;
        }
        for(int i=1;i<=m;i++){
            if(vis[i]){
                ans[i]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
}