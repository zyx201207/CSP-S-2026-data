#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,ans=0;
cin>>n>>m;
int a[n];
for(int i=1;i<=n;i++){
cin>>a[i];
}
for(int i=1;i<=m;i++){
for(int j=1;j<=n;j++){
if(a[i]&&a[j]>ans) ans=a[i]&&a[j];
}
}
cout<<ans;
}
