#include<bits/stdc++.h>
using namespace std;
int n,m,a[500009],b[500009],c[500009],d[500009];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int pashu=1;
        for(int j=i;j<=n;j++){
            if(b[a[j]]>0){
                for(int k=pashu-1;k>=1;k--){
                    pashu--;
                    b[c[k]]--;
                    if(c[k]==a[j]){
                        c[k]=0;
                        break;
                    }
                    c[k]=0;
                }
            }
            b[a[j]]++;
            c[pashu]=a[j];
            pashu++;
        }
        for(int j=1;j<=m;j++){
            if(b[j]!=0){
                d[j]++;
                b[j]=0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<d[i]<<" ";
    }
    return 0;
}
