#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);

long long n=0,m=0,i=0,s=1,a[600007]={0},d=0;
cin>>n>>m;
while(i<n){
i++;
cin>>a[i];
}
sort(a+1,a+n+1);
i=1;
while(i<n){
if(a[i]==a[i+1]){
s++;
d++;
}
i++;
}
while(m>0){
int k=(s-d)*(a[s+1-d]-a[s-d]);
if(m>=k){
m-=k;
s++;
}
}
cout<<s;
return 0;
}
