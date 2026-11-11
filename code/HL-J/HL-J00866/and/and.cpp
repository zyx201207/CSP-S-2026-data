#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
long long n,m,max=0;cin>>n>>m;
int a[n+5];
for(int i=0;i<n;i++){
cin>>a[i];
if(max<a[i-1]and a[i])max=a[i-1]and a[i];}
cout<<max<<endl;
return 0;
}