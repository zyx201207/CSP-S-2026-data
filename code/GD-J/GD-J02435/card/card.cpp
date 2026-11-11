#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[505][205];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int ans[100005];
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        b[i][a[i]]=b[i-1][a[i]]+1;
        for(int j = 1;j<=m;j++){
            if(j==a[i])continue;
            b[i][j]=b[i-1][j];
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if((b[n][j]-b[i-1][j])%2==1)ans[j]++;
        }
    }
    for(int i = 1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}

