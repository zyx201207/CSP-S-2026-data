#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        bool vis[N]={};
        int k=1,table[N]={},flag[N]={};
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                for(int l=k;l>=1;l--){
                    table[l]=-1;
                    if(a[l]==a[j])break;
                }
            }else table[k++]=a[j];
        }
        for(int j=1;j<=k;j++){
            if(table[j]!=-1){
                flag[table[j]]++;
            }
        }
        for(int j=1;j<=k;j++){
            if(flag[j]!=0)ans[table[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
