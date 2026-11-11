#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1000;
int n,m,a[N],b[N][100],c[N],ans;
int main( ){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ans=a[n];
    for(int i=n-1,j=2;j<=m;j++,i--){
        ans=ans&a[i];
    }
    cout<<ans;
return 0;}
