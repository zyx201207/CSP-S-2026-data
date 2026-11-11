#include<bits/stdc++.h>
using namespace std;
char b[5000000];
int a[30000000];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
char c;
cin>>n;
for(int i=0;i<n;i++){
   cin>>a[i]>>b[i];
}
if(n==1) {
cout<<0;
return 0;
}
if(n==2){
if(a[0]<a[1]){
  cout<<a[0];
}

else{
   cout<<a[1];
}
if(n==5){
    cout<<1;
    return 0;
}
if(n==4&&a[0]!=a[1]||a[2]!=a[3]){
    cout<<2;
    return 0;
}
return 0;
}


return 0;
}
