#include<bits/stdc++.h>
using namespace std;
int c,t,n,m;
int a[5005];
long long ans;
int mi,p;
void dfs(int x,int y,int s){
    if(x==y){
        if(s<mi){
            mi=s;
            p=1;
        }else if(s==mi){
            p++;
        }
        return;
    }
    for(int j=x+1;j<=n;j++){
        if(a[j]-a[x]<=m){
            dfs(j,y,s+1);
        }else return;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mi=INT_MAX;
                p=0;
                dfs(i,j,0);
                if(p==2)ans++;
            }
        }
        cout<<ans;
    }
    return 0;
}
