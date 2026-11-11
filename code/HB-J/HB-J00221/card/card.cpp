#include <bits/stdc++.h>
using namespace std;
int main(){
   stack<int>s;
   int total[10005],a[10005];
   bool flag[100005];
   int n,m;
   freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);
   cin >> n >>m;
for(int i=1;i<=n;i++){
    total[i]=0;
    cin >> a[i];}
for(int k=1;k<n;k++){
    for(int j=k;j<=m;j++) flag[j]=true;
   for(int i=k;i<=n;i++){
   if(flag[a[i]]) s.push(a[i]);
   else{
    while(s.top()!=a[i]) s.pop();
    s.pop();
    s.push(a[i]);
   }
   flag[a[i]]=false;
   }
   for(int j=1;j<=n;j++){
    while(!s.empty()){
        total[s.top()]++;
        s.pop();
    }
   }}
   for(int i=1;i<=m;i++){
   cout << total[i]<<" ";}
   return 0;}
