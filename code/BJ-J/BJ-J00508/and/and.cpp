#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    long long m,n;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
       cin>>a[i];
    }
    int ans=0;
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                    if(i==j){
                        continue;
                    }
                    ans=max(ans,a[i]&a[j]);
            }
        }
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
    }
    int tmp;
    if(m=n-1){
            for(int i=1;i<=n;i++){
                tmp=2e10-1;
                for(int j=1;j<=n;j++){
                    if(j==i){
                        continue;
                    }
                    tmp=tmp&a[i];
            }
            ans=max(ans,tmp);
        }
    }
    cout<<ans;
// i love noi
    return 0;
}
