#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,a[100],ans=0,m,k=2;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
                if(a[i]<1) k=1;
            if(a[i]+i==a[i]||a[i]+j==a[i]+i){
                ans++;
            }
        }
    }
    cout<<ans-k;
    return 0;
    //rp++!!!
}
