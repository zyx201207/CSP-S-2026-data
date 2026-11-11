#include<bits/stdc++.h>
using namespace std;
int n,d;
int a[500005];
int t[50005];
int mi;
void dfs(int x,int l,int sum){
    if(x==l){
        mi=min(mi,sum);
        t[sum]++;
        return ;
    }
    for(int i=x+1;i<=l;i++){
        if(a[i]-a[x]<=d){
            dfs(i,l,sum+1);
        }else{
            break;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                memset(t,0,sizeof t);
                mi=INT_MAX;
                dfs(i,j,0);
                if(mi!=INT_MAX&&t[mi]==2)ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
