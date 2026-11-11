#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    char a[500005],fi;
    string f,f2;
    int ai[500005],n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=0;k<n;k++){
                if(f[k]==a[j]){
                    for(int l=1;l<=k;l++){
                        f2[l]=f[l];
                        f=f2;

                    }
                }f+=a[j];
            }
        }
        for(int j=1;j<=m;j++){
            for(int k=0;k<n;k++){
                if(f[k]==j){
                    ai[j]++;
                }
            }
        }
    }for(int i=1;i<=m;i++){
        cout<<ai[i];
    }
}
