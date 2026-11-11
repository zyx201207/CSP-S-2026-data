#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool vis[200005];
int main(){
    ios::sync_with_stdio(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=30;i>=0;i--){
        int num=0;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&((a[j]>>i)&1)==1){
                num++;
            }
        }
        if(num>=m){
            ans+=1<<i;
            for(int j=1;j<=n;j++){
                if(!vis[j]&&((a[j]>>i)&1)==0){
                    vis[j]=1;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}