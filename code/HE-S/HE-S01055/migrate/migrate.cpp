#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[305],s[305][305],ans;
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
cin>>c>>t;
while(t--){
cin>>n>>d;
if(n<=9){
for(int i=1;i<=n;i++)  cin>>x[i];
for(int l=1;l<=n;l++){
for(int r=l+2;r<=n;r++){
for(int i=l+1;i<r;i++){
if(x[i]-x[l]<=d&&x[r]-x[i]<=d)  s[l][r]++;
}
if(s[l][r]==2)  ans++;
}
}
cout<<ans<<'\n';
for(int i=1;i<=9;i++){
for(int j=1;j<=9;j++){
s[i][j]=0;
}
}
}
ans=0; 
}
fclose(stdin);
fclose(stdout);
return 0;
}
