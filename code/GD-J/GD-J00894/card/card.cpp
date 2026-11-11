#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],cnt,vis[500005],ans[300005];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
if(n>5000){
for(long long i=1;i<=n;i++){
cin>>a[i];
if(a[i]!=a[i+1]){
ans[a[i]]=i;
}
}
for(long long i=1;i<=m;i++){
cout<<ans[i]<<" ";
}
return 0;
}
for(long long i=1;i<=n;i++){
cin>>a[i];
}
for(long long i=1;i<=n;i++){
cnt=0;
for(long long j=i;j<=n;j++){
if(vis[a[j]]){
while(cnt){
vis[b[cnt]]=0;
cnt--;
if(b[cnt+1]==a[j]){
break;
}
}
b[++cnt]=a[j];
vis[a[j]]=1;
}
else{
b[++cnt]=a[j];
vis[a[j]]=1;
}
}
for(long long i=cnt;i;i--){
ans[b[i]]++;
vis[b[i]]=0;
}
}
for(long long i=1;i<=m;i++){
cout<<ans[i]<<" ";
}
return 0;
} 
