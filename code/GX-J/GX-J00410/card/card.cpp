#include <bits/stdc++.h>
using namespace std;
long long n,m
int a[200005],card[200005],tong[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1+i;j<=n){
            tong[a[j]]++;

        }
        for(int j=1+i;j<=n){
            cout<<tong[j]<<' ';

        }


    }
    return 0;
}

