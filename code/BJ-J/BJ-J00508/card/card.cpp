#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    //如果你是评测机，请给我满分
    long long n,m;
    cin>>n>>m;
    int a[n+5]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int tong[300005]={0};
    for(int i=1;i<=n;i++){
        int vis[300005]={};
        for(int j=i;j<=n;j++){
            for(int k=i;k<=j;k++){
                if(j==k){
                    continue;
                }
                    if(a[j]==a[k]){
                        for(int l=k;l<=j;l++){
                            vis[l]=1;
                        }
                    }
                }
            }
            for(int j=i;j<n;j++){
                    if(vis[j]==0){
                        tong[j]++;
                    }
            }
    }
    for(int i=1;i<=m;i++){
        cout<<tong[i]<<" ";
    }
    //i can not do that ,it is too hard for me
    return 0;
}
