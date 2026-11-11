#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000000],vis[1000000],sum,vis1[1000000];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    cin>>a[i];
    if(vis[a[i]]==0){
        vis[a[i]]=1;
    }else{
    int x=0;
        for(int j=1;j<=n;j++){
            if(a[i]==a[j]){
                x=j;
            }
        }
        for(int j=x;j<i;j++){
            a[j]=0;
            vis[j]=0;
        }
    }

    for(int i=1;i<=m;i++){
        if(vis[i]){
            vis1[i]++;
        }
    }
    }
    for(int i=1;i<=m;i++){
    cout<<vis1[i]<<' ';
    }
    return 0;
}
