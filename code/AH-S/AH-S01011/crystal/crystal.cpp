#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=500010;
LL a[N],c[N],z,ans=1,ans1=0,b=1;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int n;
LL m;
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
sort(a+1,a+n+1);
for(int i=1;i<n;i++){
	c[i]=a[i+1]-a[i];
}
for(int i=1;i<=n;i++){
	if(z>m){
		ans--;
		ans1=max(ans,ans1);
		z=z-(a[i]-a[b]);
		b++;
	}
	z=z+c[i]*(i-b+1);
	if(i!=n) ans++;
}
if(z<=m&&ans>ans1) ans1=ans;
cout<<ans1;
return 0;}
