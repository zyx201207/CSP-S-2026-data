#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
int n,m,i=0,a[600007]={0},s[400007]={0};
cin>>n>>m;
while(i<n){
i++;
cin>>a[i];
}
i=0;
while(i<n){
a[i]=0;
i++;
int j=i;
while(j<n){
int k=a.find(a[j]);
if(k!=0&&k>=j){
j=k;
}else{
s[a[j]]++;
j++;
}
}
i=0;
while(i<m){
i++;
cout<<s[i]<<" ";
}
return 0;
}
