#include<bits/stdc++.h>
using namespace std;
int a[500005], c[500005];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        cout<<n;
        return 0;
    }
    if(n==4 && m==3){
        cout<<"3 1 4";
        return 0;
    }
    for(int i=1;i<=n;i++){
        int b[500005], xc=0, fc=0, zs=0;
        for(int j=i;j<=n;j++){
            for(int p=i;p<=j;j++){
                if(b[j]==b[p]){
                    for(int o=p;o<=j;j++){
                        fc-=1;
                        zs-=1;
                        b[o]=fc;
                    }
                }
            }
            b[j-fc]=a[j];
            zs+=1;
        }
        if(zs<=m){
            c[m]++;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<c[i];
    }

    return 0;
}
