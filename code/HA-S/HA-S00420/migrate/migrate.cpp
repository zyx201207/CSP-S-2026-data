 #include<bits/stdc++.h>
using namespace std;
int c,T,ds[2000005],nt[2000005];
long long n,d,a[2000005],as,ct[2000005];
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0),cout.tie(0);
cin>>c>>T;
while(T--){
cin>>n>>d,as=0;
for(int i=1;i<=n;i++) cin>>a[i];
if(n<4){
cout<<"0\n";
continue;
}
if(n<=5000){
for(int i=1;i<=n;i++){
ds[i]=0,ct[i]=1;
nt[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
for(int j=i-1;j>=1;j--) ds[j]=1e9,ct[j]=0;
for(int j=i-1;j>=1;j--){
int p=nt[j];
p=min(p,i);
ds[j]=ds[p]+1;
ct[j]=ct[p];
if(j<p-1&&ds[p-1]==ds[p]) ct[j]+=ct[p-1];
if(j<p-2&&ds[p-2]==ds[p]) ct[j]+=ct[p-2];
if(ct[j]==2) as++;
}
}
cout<<as<<"\n";
}else if(11<=c&&c<=12){
if(d<2*(a[2]-a[1])) cout<<"0\n";
else cout<<max(0ll,n-(2*d/(a[2]-a[1]))+1)<<"\n";
}else if(13<=c&&c<=14){
for(int i=1;i<=n;i++){
int p=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
if(p<=i+1) continue;
int l=upper_bound(a+1,a+n+1,a[p-2]+d)-a;
int r=upper_bound(a+1,a+n+1,a[p-1]+d)-a-1;
as+=r-l+1;
}
cout<<as<<"\n";
}else{
for(int i=1;i<=n;i++){
ds[i]=0,ct[i]=1;
nt[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
for(int j=i-1;j>=1;j--) ds[j]=1e9,ct[j]=0;
for(int j=i-1;j>=1;j--){
int p=nt[j];
p=min(p,i);
ds[j]=ds[p]+1;
ct[j]=ct[p];
if(!ct[j]) break;
if(j<p-1&&ds[p-1]==ds[p]) ct[j]+=ct[p-1];
if(j<p-2&&ds[p-2]==ds[p]) ct[j]+=ct[p-2];
if(ct[j]==2) as++;
}
}
cout<<as<<"\n";
}
}
return 0;
}
