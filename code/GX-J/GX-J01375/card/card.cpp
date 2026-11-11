#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],b[1000000],z,c[1000000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=z;j++){
            b[j]==0;
        }
        z=0;
        for(int j=i;j<=n;j++){
            for(int k=1;k<=z;k++){
                if(b[k]==a[j]){
                    for(int h=k;h<z;h++){
                        b[h]=0;
                    }
                }
            }
            z++;
            b[z]=a[j];
        }
        for(int j=1;j<=z;j++){
            c[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
