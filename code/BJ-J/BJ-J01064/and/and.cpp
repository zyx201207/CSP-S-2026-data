#include<bits/stdc++.h>
using namespace std;
int a[100005],vis[100005],maxx,ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    if(m==1){
        cout<<maxx;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                ans=max(ans,a[j]&a[i]);
            }
        }
    }
    cout<<ans;
    return 0;
}
