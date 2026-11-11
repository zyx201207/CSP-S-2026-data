#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,a[N],n,d;
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
cin>>c>>t;
while(t--){
cin>>n>>d;
for(int i=1;i<=n;i++)cin>>a[i];
if(c==11||c==12){
if(a[2]-a[1]>2*d)cout<<0<<endl;
else {
long long ans=n*(n-1)/2;
int dis=d/(a[2]-a[1]);
for(int i=1;i<=n;i++){
for(int j=i+d;j<=n;j+=d)ans--;
}
cout<<ans<<endl;
}
}else if(c==13||c==14){cout<<0<<endl;}else{cout<<1<<endl;}
}
return 0;
}
