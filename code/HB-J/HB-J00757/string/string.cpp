#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005],ans=INT_MAX,vis[200005];
char s[200005];
string z,b;
void dfs(int x,int cnt){
    if(x==z.size()+1){
        for(int i=0;i<z.size();i++){
            if(vis[i]){
                b[i]=z[i];
                z[z.size()-i+1]=z[i];
            }
        }
        if(b!=z) return;
        ans=min(ans,cnt);
        return;
    }
    vis[x]=1;
    dfs(x+1,cnt+1);
    vis[x]=0;
    dfs(x+1,cnt);
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
        for(int j=1;j<=a[i];j++){
            z+=s[i];
        }
    }
    b=z;
    reverse(z.begin(),z.end());
    dfs(0,0);
    cout<<ans;
    return 0;
}
