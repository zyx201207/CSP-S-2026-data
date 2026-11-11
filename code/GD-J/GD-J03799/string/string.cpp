#include<bits/stdc++.h> 
using namespace std;
int n,m[200001],t[200000001],l,r,c,v;
char s[200001];
int d(int p){
int u=0,c=1;
while(p!=0){
t[c]+=u;
t[c]+=p%10;	
u=t[c]/10;
t[c]%=10;
c++;
p/=10;
}
t[c]+=u;
v=max(c,v);
return 0;	
}
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
cin>>m[i]>>s[i];		
}
l=1,r=n;
while(l<r){	
if(s[l]!=s[r]){
d(min(m[l],m[r]));
}
m[l]-=min(m[l],m[r]);
m[r]-=min(m[l],m[r]);
if(m[l]==0)
l++;
if(m[r]==0)
r--;		
}
if(t[v]==0)
v--;
for(int i=v;i>=1;i--){
cout<<t[i];
}
return 0;
}

