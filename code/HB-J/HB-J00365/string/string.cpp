#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
int n=0,i=0,xi=0;
long long a[300007]={0},x=0;
char c[300007]={' '};
cin>>n;
while(i<n){
i++;
cin>>a[i-xi]>>c[i-xi];
if(c[i-xi]==c[i-xi-1]){
a[i-xi-1]+=a[i-xi];
a[i-xi]=0;
c[i-xi]=' ';
xi++;
}
}
i-=xi;
xi=1;
while(xi<i){
if(c[xi]!=c[i]){
x+=min(a[xi],a[i]);
}
if(min(a[xi],a[i])==a[xi]){
a[i]-=a[xi];
a[xi]=0;
xi++;
}else{
a[xi]-=a[i];
a[i]=0;
i--;
}
};
cout<<x;
return 0;
}
