#include<bits/stdc++.h>
using namespace std;
int main(){freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,a[200005];
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>a[i];
sort(a+1,a+n+1);
if(a[1]==a[2])cout<<a[1];
else if(a[1]==1)cout<<a[3];
else cout<<a[2]%a[1];
return 0;}
