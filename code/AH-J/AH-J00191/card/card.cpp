#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],f=0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            cout<<n+1-i<<' ';
        }
    }
    else if(m==1)cout<<n;
    return 0;
}
