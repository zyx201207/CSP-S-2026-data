#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(long long i=1;i<=n;i++){
cin>>a[i]>>c[i];
}
for(long long i=1,j=n;i<j;i++){
while(a[i]>a[j] && i<j){
if(c[j]!=c[i]){
ans+=a[j];
}
a[i]-=a[j];
j--;
}
if(a[j]>a[i]){
if(c[j]!=c[i]){
ans+=a[i];
}
a[j]-=a[i];
}
else if(a[j]==a[i]){
if(c[j]!=c[i]){
ans+=a[i];
}
j--;
}
}
cout<<ans;
return 0;
} 
