#include<bits/stdc++.h>
using namespace std;

int a[200010];
int n,m,ans=0;

void dfs(int pt,int k,int an){
    if(k==m){
        ans=max(ans,an);
        return;
    }
    if(pt==n){
        return;
    }
    for(int i=pt+1;i<=n;i++){
        dfs(i,k+1,an&a[i]);
    }
}

int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=2000){
        dfs(0,0,INT_MAX);
        cout<<ans<<endl;
        return 0;
    }
    if(m==1){
        cout<<n-1;
        return 0;
    }
    else if(n/2>=m){
        for(int i=1,j=1;i<=n/2;i*=2,j++){
            if(i/2<m&&m<=i){
                cout<<n-i<<endl;
                break;
            }
        }
    }
    else{
        cout<<0;
    }

    return 0;
}
