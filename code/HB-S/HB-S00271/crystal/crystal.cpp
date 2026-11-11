#include<bits/stdc++.h>
using namespace std;
const int mx=500030;
int n,m,a[mx],l,c,k,co=1,ma;
int kb(int i,int j){
c=a[i];
k=c-a[j];
if(j>=0){
if(k<=l){
    co++;
    kb(i,j-1);
}
else{
    if(co>ma){
        ma=co;
        co=1;
        l=m;
    }
    i--;
    kb(i-1,i-2);
}
}
}
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;i++){
    cin>>a[i];
}
sort(a,a+n);
l=m;
kb(n-1,n-2);
cout<<ma;
return 0;
}
