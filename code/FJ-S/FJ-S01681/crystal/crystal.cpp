#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,z,hz,ans=1,lm;
long long a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	z=n/2+1;
	hz=z;
	lm=m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=n;i>z;i--){
		if(a[i]==a[z]){
			ans++;
			hz++;
		}
	}
	for(long long i=z-1;i>=1;i--){
		if(m!=0) {
		m-=a[z]-a[i];
		b[i]=a[z];
		ans++;}
	}
	if(m!=0&&b[1]==a[z]){
		for(long long i=m;i>=0;){
			i-=(a[hz]-a[z])*z;
			ans++;
			hz++;
			z++;
		}
	}
	cout<<ans;
	return 0;
 } 
