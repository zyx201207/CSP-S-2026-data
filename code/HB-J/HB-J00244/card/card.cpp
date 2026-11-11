#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],vis[10005],ans[100005],p[10005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int cnt=1;
        memset(vis,sizeof(vis),0);
        memset(p,sizeof(p),0);
        for(int j=i+1;j<=n;j++){
            if(vis[a[j]]!=0){
                int loc;
                for(int k=1;k<=cnt;k++){
                    if(p[k]==a[j]){
                        loc=k;
                        break;
                    }
                }
                for(int k=loc;k<=cnt;k++){
                    p[k]=0;
                }
                cnt=loc;
                p[cnt]=a[j];
                vis[a[j]]=1;
                cnt++;
                for(int k=1;k<=cnt;k++){
                    cout<<p[k]<<" ";
                }
                cout<<endl;
            }
            else if(vis[a[j]]==0){
                p[cnt]=a[j];
                cnt++;
                vis[a[j]]=1;
                for(int k=1;k<=cnt;k++){
                    cout<<p[k]<<" ";
                }
                cout<<endl;
            }
        }
        for(int j=1;j<=cnt;j++){
            ans[p[j]]++;
            cout<<p[j]<<" ";
        }
        cout<<endl;
        for(int j=1;j<=3;j++){
            cout<<ans[j]<<" ";
        }
        cout<<endl<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[a[i]]<<" ";
    }
    return 0;
}
