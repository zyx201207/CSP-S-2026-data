#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];bool sz[300005];int cx[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;int kl=0;
    for(int i=1;i<=n;i++){cin>>a[i];}
    for(int i=0;i<n;i++){
        for(int j=1+i;j<=n;j++){
            if(sz[a[j]]){kl=j;memset(sz+1,0,sizeof(sz));}
            else sz[a[j]]=1;
        }
        for(int j=kl;j<=n;j++){
            cx[a[j]]++;
        }
        memset(sz+1,0,sizeof(sz));
    }
    for(int i=1;i<=m;i++){
        cout<<cx[i]<<' ';
    }
    return 0;
}
