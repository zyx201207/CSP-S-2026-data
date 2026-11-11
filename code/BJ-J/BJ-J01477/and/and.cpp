#include<bits/stdc++.h>
using namespace std;
int h;
int main(){
//freopen("and.in","r",stdin);
//freopen("and.out","w",stdout);
int n,m;
cin>>n>>m;
h=m;
long long a[n+5];
for(int i=1;i<=n;i++){
cin>>a[i];
}
if(m==1){
    sort(a+1,a+n+1);
    cout<<a[n];
    return 0;
}
int maxm=-1;
if(m==3){
    for(int i=n;i>0;i--){
    for(int k=i-1;k>0;k--){
for(int j=k-1;j>0;j--){
        h=(a[i]&a[j]&a[k]);
  maxm=max(maxm,h);

}
}
}
cout<<maxm;
return 0;
}
for(int i=n;i>0;i--){
for(int j=i-1;j>0;j--){
        h=(a[i]&a[j]);
  maxm=max(maxm,h);

}
}
cout<<maxm;



return 0;
}
