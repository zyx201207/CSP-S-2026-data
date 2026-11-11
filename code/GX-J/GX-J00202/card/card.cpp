#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000100],b[1000100];
int t[1000100];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    int n1=n;
    while(n1--){
        for(int i=n-n1;i<=n;i++){
            t[a[i]]++;
        }
        for(int i=n-n1;i<=n;i++){

            for(int j=i+1;j<=n;j++){
                if(a[j]==a[i]){
                    for(int k=j-1;k>=i;k--){
                        t[a[k]]--;
                    }
                    i=j;

                }
            }
        }
    }
    for(int i=1;i<=m;i++){
            cout<<t[i]<<' ';
    }
    return 0;
}
