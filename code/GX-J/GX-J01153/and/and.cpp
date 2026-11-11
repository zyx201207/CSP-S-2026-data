#include <bits/stdc++.h>
using namespace std;
int n,m,a[9999999],b[9999999],c,o;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin.tie(nullptr);
    cin>>n>>m;
    o=n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    reverse(a,a+n);
    for(int k=0;k<=n;k++){b[k]=a[k]-a[k+1];c=min(b[k],b[k+1]);}
    for(int j=0;j<=o;j++){
        if(c==b[j]){
            c=j;
            break;
}}
    reverse(a,a+n);
    cout<<a[c];
return 0;}
