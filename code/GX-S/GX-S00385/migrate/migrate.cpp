#include<bits/stdc++.h>
using namespace std;
long long n,d,x[2000005],f[2000005];
int dfs(int i,int k){
    int anss=0;
    while(i<=k){
        for(int j=k;x[j]-x[i]>d;j--){
            if(x[j-1]-x[i]<=d) i=j-1;
            anss++;
        }
        if(x[k]-x[i]<=d){
            anss++;
            return anss;
        }
    }
}
int aaa(int j,int k){
    for(int i=j+1;x[i]-x[j]<=d;i++){
        if(f[dfs(i,k)]==1) return 1;
        else f[dfs(i,k)]=1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
        int ans=0;
        for(int j=1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(x[k]-x[j]<=d){
                    ans+=aaa(j,k);
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
