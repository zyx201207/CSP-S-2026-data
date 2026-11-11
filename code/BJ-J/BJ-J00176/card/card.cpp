#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],t[N],k[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        t[a[i]]++;
        k[a[i]]+=t[a[i]]*i;
    }
    for(int i=1;i<=m;i++){
        cout<<k[i]<<endl;
    }
    return 0;
}
