#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
long long n,m;
char a[1e9];
cin>>n>>m>>a[1e9];
for(int i=1;i<=m;i++){
for(int j=1;j<=n;j++){
    a[i]^a[j];
}
int l=a[i]^a[j];
ios(a[i]^a[j],a);
cout<<l;
return o;
}
