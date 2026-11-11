#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n;
cin>>n;
long long a[1e9];
cin>>a[1e9];
int b[1e9],cnt=0;
for(int i=1;1<=n;i++){
for(int i=1;i<=a;i++){
a=n/2+i;
b=n/2-i;
if(a[n/2+i]==b[n/2-i])cnt=0;}}
else{for(int j=1;j<=a;j++){
    if(a[n/2+i]==b[n/2+i+26-'A']){cnt++;}
    else{b=b[j+1];cnt++;}}
}
cout<<cnt;
return o;
}
