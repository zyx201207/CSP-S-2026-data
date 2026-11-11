#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,a[25005]={},b[25005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[a[j]]++;
        }
    }for(int i=0;i<n;i++){
        if(b[i]!=0){
            cout<<b[i]<<" ";
        }
    }


    return 0;
}
