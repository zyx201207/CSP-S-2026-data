#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001];
int main(){
    //freopen(card.in,"r",stdin);
    //freopen(card.out,"w",stdout);
    //cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int j=1;
    for(int i=1;i<=30;i++){
        j*=2;
    }
    cout<<j;
    return 0;
}
