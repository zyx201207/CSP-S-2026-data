#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,mx=-1;
int a[200010];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }if(m==1){
        for(int i=1;i<=n;i++){
            mx=max(mx,a[i]);
        }
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mx=max(mx,a[i]&a[j]);
            }
        }
    }
    if(m==3){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    mx=max(mx,a[i]&a[j]&a[k]);
                }
            }
        }
    }cout<<mx;
    return 0;
}
