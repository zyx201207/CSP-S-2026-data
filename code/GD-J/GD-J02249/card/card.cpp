#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],mi[300005],d[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int di=1;
        for(int j=i;j<=n;j++){
            di++;
            bool dk=false;
            int dik=di;
            for(int k=1;k<di;k++){
                if(k==di-1) break;
                if(dk){
                    d[k]=0;
                }if(d[k]==a[j]){
                    dk=true;
                    d[k]=0;
                    dik=k;
                }
            }
            di=dik;
            d[di]=a[j];
        }
        for(int j=1;j<=di;j++){
            mi[d[j]]++;
            d[j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<mi[i]<<' ';
    }
    return 0;
}
