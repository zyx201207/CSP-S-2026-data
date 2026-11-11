#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int w=1;w<=n;w++){
        int u=w;
        while(u<=n){
            bool u1=1;
            for(int i=u+1;i<=n;i++){
                if(a[u]==a[i]&&u1==1){
                    u1=0;
                    u=i;
                }
            }
            if(u1==1){
                ans[a[u]]++;
                u++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
