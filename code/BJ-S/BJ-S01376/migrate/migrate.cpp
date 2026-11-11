#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[2000005];
int ans=INT_MAX;
int cnt=0;
bool f[200005];
void dfs(int x,int e,int sum){
    if(x==e){
        if(sum==ans){
            cnt++;
        }else if(sum<ans){
            ans=sum;
            cnt=1;
        }
        return;
    }
    if(f[x]==1){
        return;
    }
    f[x]=1;
    for(int i=x-1;i>0;i--){
        if(a[x]-a[i]<=d&&f[i]==0){
        dfs(i,e,sum+1);
     }
    }
    for(int i=x+1;i<=n;i++){
        if(a[i]-a[x]<=d&&f[i]==0){
        dfs(i,e,sum+1);
    }
    }
    f[x]=0;
    return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        int zans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            for(int j=1;j<i;j++){
                ans=INT_MAX;
                cnt=0;
                dfs(a[i],a[j],0);
                if(cnt==2){
                    zans++;
                }
            }
        }
        cout<<zans<<'\n';
    }
    return 0;
}
