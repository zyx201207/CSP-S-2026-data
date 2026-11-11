#include<bits/stdc++.h>
using namespace std;
int main (){
long long n,m,a[100005],maxx;
freopen（“and.in”，“r”,stdin);
freopen（“and.out”，“w”,stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
cin>>a[i];
maxx=a[i];
if(a[i]>a[i]) a[i]=maxx;}
cout<<maxx;

return 0;
}

