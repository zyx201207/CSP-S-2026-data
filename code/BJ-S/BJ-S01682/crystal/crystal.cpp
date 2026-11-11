#include<bits/stdc++.h>
using namespace std
int a[100001];
int main(){
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+n+1);
if(a[i]/m!=0){
a[i]-1;
}
for(int i=1;i<=m;i--){
if(i=a[i]%m==0){
ans++;
}else if(i<a[i]%m==0){
i+1;
}
}
cout<<ans;
return 0;
}
