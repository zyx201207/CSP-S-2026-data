#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[1000086],b[1000000]={};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int k=1;k<=n;k++){
        for(int i=k+1;i<=n;i++){
            for(int j=k;j<i;j++){
                if(a[j]==a[i]){
                    for(int hh=j+1;hh<=i;hh++){
                        a[hh]=0;
                    }
                }
            }
        }
        if(k==n){
            b[a[n]]++;
        }
        for(int i=1;i<=n;i++){
            if(a[i]!=0){
                b[a[i]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(b[i]!=0){
            cout<<b[i]<<" ";
        }
    }
    return 0;
}
