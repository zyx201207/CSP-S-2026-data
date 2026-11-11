#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long n,m,a[N],maxs=-1;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
cin>>a[i];
}
sort(a+1,a+n+1);
long long b=0,s=a[n];
for(int i=n;i>=1;i--){
	b=(b+1)%m;
	s=(s&a[i]);
if(b==0){
	maxs=max(maxs,s);
	s=a[i-1];
}
}
cout<<maxs;
}
