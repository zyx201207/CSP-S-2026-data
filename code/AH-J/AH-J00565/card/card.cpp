#include<bits/stdc++.h>
using namespace std;
int a[500001],s[500001];
bool b[500001];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m;
stack<int>crd;
cin>>n>>m;
for(int i=0;i<n;i++) cin>>a[i];
for(int i=0;i<n;i++){
printf("i:%d\n",i);
for(int j=i;j<n;j++){
if(b[a[j]]) while(crd.top()!=a[j]){
b[crd.top()] = 0;
crd.pop();
}
else{
crd.push(a[j]);
b[a[j]] = 1;
}
}
for(int j=0;j<n;j++) s[j] += b[j];
while(!crd.empty()){
b[crd.top()] = 0;
crd.pop();
}
}
for(int i=1;i<=m;i++) cout<<s[i]<<' ';
return 0;
}
//ice ice ice
//the hardness of pixel blocks is king's road,your cartoon huafeng have no jiqiao!
//cute world is more popular among most people,your hardness had been lost by the time!
//naochi vs guzhenxing
