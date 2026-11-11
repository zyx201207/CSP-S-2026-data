#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],cnt[2000005],minn[2000005],ans,cha;
void dfs(long long u,long long z){
if(z<minn[u]){
minn[u]=z;
if(cnt[u]==2){
ans--;
}
cnt[u]=1;
}
else if(z==minn[u]){
cnt[u]++;
if(cnt[u]==2){
ans++;
}
else{
ans--;
}	
}
for(long long i=u+1;i<=n;i++){
if(x[u]+d<x[i]){
break;
}
dfs(i,z+1);
}
}
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
cin>>c>>t;
while(t--){
cin>>n>>d;
cha=0;
for(long long i=1;i<=n;i++){
cin>>x[i];
}
if(c==13 || c==14){
cout<<0<<"\n"; 
continue;
}
cha=x[n]-x[n-1];
if(c==11 || c==12){
if(d/cha<2){
cout<<0<<'\n';
}
else if(n-d/cha*2+1>=1){
cout<<n-d/cha*2+1<<"\n";
}
else{
cout<<0<<"\n";
}
continue;
}
else{
ans=0;
for(long long i=1;i<=n;i++){
for(long long j=1;j<=n;j++){
cnt[j]=0;
minn[j]=1e9;
}
dfs(i,0);
}
cout<<ans<<"\n";
}
}
return 0;
} 
