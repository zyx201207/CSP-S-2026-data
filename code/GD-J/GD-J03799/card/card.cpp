#include<bits/stdc++.h> 
using namespace std;
int n,m,a[500001],r[300001],t[300001];
stack<int>s;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
s.push('*');
for(int i=1;i<=n;i++)
cin>>a[i];
for(int i=1;i<=n;i++){
int e=1;
for(int j=i;j<=n;j++){
if(t[a[j]]!=0){
int y=e;
for(int o=t[a[j]];o<y;o++){
s.pop();
e--;
}	
}
s.push(a[j]);
t[a[j]]=e;
e++;		
}
for(int j=1;j<e;j++){
r[s.top()]++;
s.pop();		
}
fill(t,t+m+1,0);
} 
for(int i=1;i<=m;i++){
cout<<r[i]<<" ";
}
return 0;
}


