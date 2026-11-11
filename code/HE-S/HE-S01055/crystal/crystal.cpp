#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5005],c[5005][5005],s,ans=0,x;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
if(n<=1000){
for(long long i=1;i<=n;i++)  cin>>a[i];
for(long long i=1;i<=n;i++){
for(long long j=1;j<=n;j++){
if(a[i]>=a[j]&&i!=j)  c[i][j]=a[i]-a[j];
else  c[i][j]=1e9+5;
}
}
for(long long i=1;i<=n;i++){
sort(c[i]+1,c[i]+n+1);
for(long long j=1;j<=n;j++){
if(c[i][j]==1e9+5){
ans=max(ans,j);
break;
}
s=s+c[i][j];
if(s>m){
ans=max(ans,j);
break;
}
}
s=0;
}
cout<<ans<<'\n';
}else{
for(int i=1;i<=n;i++)  cin>>x;
for(int i=1;i*i<=m;i++){
if(i*(i+1)/2>m){
cout<<i-1;
return 0;
}
} 
}
fclose(stdin);
fclose(stdout);
return 0;
}
