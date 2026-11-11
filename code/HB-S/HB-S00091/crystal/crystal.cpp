#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("crystal.in","r","stdin");
freopen("crystal.out","w","stdout");
long n,m,c=0;
cin>>n>>m;
long a[n];
if(m==0){
cout<<0;
break;
}
for(int i=1;i<=n;i++){
cin>>a[i];
}
for(int j=1;j<=n;j++){
for(int y=2;y,=n;y++){
if(a[j]==a[y]){
c++;
a[y]+=a[j];
countinue;
}
else if(y==n){
a[j]++;
j--;
}
}
}
cout<<c;
return 0;
}
