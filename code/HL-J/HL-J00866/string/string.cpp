#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int a,b=0;
cin>>a;
long long as[a+5];
string ad[a+5];
for(int i=0;i<a;i++){
cin>>as[i]>>ad[i];}
for(int j=0;j<a/2;j++){
if(ad[j]!=ad[a-j])b++;}
cout<<b;
return 0;
}