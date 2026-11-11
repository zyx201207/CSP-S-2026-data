#include<bits/stdc++.h>
using namespace std;
int n,m,k=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int a[n+6],b[n+6],t[m+5];
    memset(t,0,sizeof(t));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
     for(int i=1;i<=n;i++){
        k=1;
        memset(b,0,sizeof(b));
        for(int j=i;j<=n;j++){
            int p=1;
            for(int l=1;l<=k;l++){
                if(a[j]==b[l]){
                    p=0;
                    k=l;
                    break;
                }
            }
            b[k++]=a[j];
        }
        k--;
        for(int j=1;j<=k;j++){
            t[b[j]]++;
        }
     }
     for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
}
