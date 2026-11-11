#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m; cin>>n>>m;
long long arr[200005]={0};
long long ans=0;
for(int i=1;i<=n;++i) cin>>arr[i];
for(int mask=0;mask!=(1<<n);mask++){
string b="";
int t=mask;
int p=0;
while(t){
if(t%2==1) p++;
b=(char)(t%2+'0')+b;
t=t/2;
}
if(p!=m) continue;
int op=0;
long long a;
while(b.size()!=n) b='0'+b; 
for(int i=0;i<b.size();i++){
if(b[i]=='1' and op==0){
a=arr[i+1]; op=1; continue;
}
if(b[i]=='1'){
a=a&arr[i+1];
}
}
if(a>ans) ans=a;
}
cout<<ans;
return 0;
} 
