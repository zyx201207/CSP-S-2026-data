#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],maxx=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            maxx=max(a[i],maxx);
        }
    }if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
            maxx=max(a[i]&a[j],maxx);
            }
        }
    }if(m==3){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                for(int k=1;k<j;k++){
                    maxx=max(a[i]&a[j]&a[k],maxx);
            }
        }
    }
    }if(m==4){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                for(int k=1;k<j;k++){
                    for(int l=1;l<k;l++){
                        maxx=max(a[i]&a[j]&a[k]&a[l],maxx);
                    }
                }
            }
        }
    }if(m==5){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                for(int k=1;k<j;k++){
                    for(int l=1;l<k;l++){
                        for(int o=1;o<l;o++){
                            maxx=max(a[i]&a[j]&a[k]&a[l]&a[o],maxx);
                        }
                    }
                }
            }
        }
    }
    cout<<maxx;
    return 0;
}
