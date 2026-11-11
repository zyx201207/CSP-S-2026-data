#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,s[200005],c=1000000;
cin>>n>>m;
int a[200005],b[200005];
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+n+1);
cout<<a[n-m];
return 0;
}
