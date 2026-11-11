#include <bits/stdc++.h>

using namespace std;

#define int long long

long long a[200005];

int nums[25],mx=-1,n,m;
bool vis[25];

void dfs(int cnt){
    if(cnt==m){
        int sum=nums[0];
        for(int i=1;i<m;i++){
            sum=(sum&nums[i]);
        }
        mx=max(mx,sum);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=true;
            nums[cnt]=a[i];
            dfs(cnt+1);
            vis[i]=false;
        }
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        dfs(0);
        cout<<mx;
        return 0;
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
