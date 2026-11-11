#include<bits/stdc++.h>
using namespace std;
long long n,ans=-100,a[200050],m;
void dfs(long long de,long long ch,long long va){
if(ch==m){
ans=max(ans,va);
}
if(ch!=0&&va<ans)return;
if(de>n)return;
if(ch==0){
dfs(de+1,ch+1,a[de]);
}
else{
dfs(de+1,ch+1,a[de]&va);
}
dfs(de+1,ch,va);
return;
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n>>m>>a[1];
long long anss=a[1],ma=0,mam=0;
ma=max(a[1],ma);
for(int i=2;i<=n;i++){
cin>>a[i];
ma=max(ma,a[i]);
anss=anss&a[i];
}
if(m==1){
cout<<ma;
return 0;
}
if(m==n){
cout<<anss;
return 0;
}
if(m==2){
long long anse=0;
for(int i=1;i<=n;i++){
for(int j=1;j<=n;j++){
if(i==j)continue;
anse=max(anse,a[i]&a[j]);
}
}
cout<<anse;
return 0;
}
dfs(1,0,0);
cout<<ans;
return 0;
}
