#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000020],vis[1000200],ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int j=30;j>=0;j--){
        int sum=0;
        for (int i=1;i<=n;i++) {
            if (vis[i]==1) continue;
            if ((a[i]>>j)&1) sum++;
        }
        if (sum>=m){
            ans|=(1<<j);
            for (int i=1;i<=n;i++){
                if (vis[i]==1) continue;
                if (((a[i]>>j)&1)==0) vis[i]=1; 
            }
        } 
    }
    cout<<ans<<"\n";
    return 0;
}
//5 3
//31 3 1 15 7
/**/
