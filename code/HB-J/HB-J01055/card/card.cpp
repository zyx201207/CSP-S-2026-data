#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],g=0,l=0,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    cout<<a[n+1]+a[n+3]+a[n+4]<<a[7]<<a[n];
    return 0;

}
