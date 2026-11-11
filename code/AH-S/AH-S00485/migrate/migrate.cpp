#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d,a[200006],ans[200005];
int road(int l,int r){
    int N, M;
    if(r-l<=2) return 0;
    for(int k=l;k<=r;k++){
        if(a[k]-a[l]>d){
            N=k-1;
            break;
        }
    }
    for(int k=r;k>=l;k--){
        if(a[r]-a[k]>d){
            M=k+1;
            break;
        }
    }
    if(N==M) return 0;
    if(a[N]+d>=a[r] && a[M]<=a[l]+d) return 1;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++)
            cin>>a[j];
        for(int u=2;u<=n;u++){
            for(int v=1;v<u;v++){
                ans[i]+=road(v,u);
            }
        }
    }
    for(int i=1;i<=t;i++) cout<<ans[i]<<endl;
    return 0;
}
