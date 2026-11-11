#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,ans=0,mx=-1;
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+n+1);
cout<<a[2];

return 0;
}

