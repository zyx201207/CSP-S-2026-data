#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];int t=-2147482646;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);

    }
    if(m==1){
        for(int i=1;i<=n;i++){
            t=a[i]&a[i-1];
        }

    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(i!=j){
                    t=max(t,a[i]&a[j]);
                }
            }
        }

    }
    else if(m==3){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                     if(i!=j&&j!=k){
                        t=max(t,a[i]&a[j]&a[k]);
                    }
                }

            }
        }
    }
    cout<<t;
    return 0;
}
