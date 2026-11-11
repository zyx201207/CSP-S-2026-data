#include <bits/stdc++.h>
using namespace std;
int a[10005];
int b[10005];
int cnt[1005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1,i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b[i]=a[i];
            for(int k=i-1;k>1;k--){
                if(b[k]==b[i]){
                    for(int y=k;y<=i;y++){
                        b[y]=b[y+2];

                    }
                }else{
                    coutinue;
                }
            }


        }
    }

    return 0;
}
