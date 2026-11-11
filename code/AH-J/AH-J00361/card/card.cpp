#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int t[500005],ans[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=1;k<=n;k++){
        memset(t,0,sizeof(t));
        for(int i=k;i<=n;i++){
            if(t[a[i]]==0){
                t[a[i]]=1;
            }else{
                for(int j=i-1;a[j]!=a[i];j--){
                    t[a[j]]=0;
                }
                t[a[i]]=0;
            }
        }
        for(int i=1;i<=m;i++){
            if(t[i]==1) ans[i]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
