#include<bits/stdc++.h>
using namespace std;
int n,m,a[500100];
struct as{
    int c[3030];
}b[3030];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int x=1;
    for(int i=1;i<=n;i++){
        x=1;
        for(int j=i;j<=n;j++){
            for(int k=1;k<=x;k++){
                if(b[i].c[k]==a[j]){
                    for(int l=k;l>=1;l--){
                        b[i].c[l]=0;
                        x--;
                    }
                    break;
                }
            }
            b[i].c[x]=a[x];
            x++;
        }
    }
    int cnt=0;
    for(int i=1;i<=m;i++){
        cnt=0;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(b[j].c[k]==i) cnt++;
            }
        }
        cout<<cnt<<" ";
    }
    return 0;
}
