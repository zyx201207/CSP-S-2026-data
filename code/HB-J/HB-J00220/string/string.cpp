#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char z[200005];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
long long j=0;
string s;
for(int i=1;i<=n;i++){
cin>>a[i];
cin>>z[i];
}
bool v=true;
for(int i=2;i<=n;i++){
if(a[i]!=a[n+1-i])v=false;
}
if(v==true){
long long ans=0;
for(int i=1;i<=n/2;i++){
if(z[i]!=z[n+1-i])ans+=a[i];
}
cout<<ans;
return 0;
}
for(int i=1;i<=n;i++){
while(a[i]--)s=s+z[i];
}
j=s.size()-1;
long long ans=0;
for(long long i=0;i<=j/2;i++){
if(s[i]!=s[j-1])ans++;
}
cout<<ans;
return 0;
}
