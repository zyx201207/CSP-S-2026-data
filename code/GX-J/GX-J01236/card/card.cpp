#include<bits/stdc++.h>
using namespace std;
int n,m,a[20000005],b[20000005];


int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;i++){
            b[i]=a[j];
        }
    }
    cout<<m;
    return 0;
}


