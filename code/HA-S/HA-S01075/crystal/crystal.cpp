#include<bits/stdc++.h>
using namespace std;
long long n,m,r,x,ans;
long long a[5000005],b[5000005],c[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	c[1]=0;
	b[1]=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(long long i=1;i<=n;i++){
		c[i]=r+b[i]*(i-1);
		r=c[i];	
	}
	for(long long i=n;i>=1;i--){
		if(c[i]<=m){
			x=i;
			break;
		}
	}
	for(long long i=x-1;i>=1;i--){
		while(a[i]<a[x]&&m>0){
			a[i]++;
			m--;
		}
		if(m==0){
			break;
		}
	}
	for(long long i=1;i<=n;i++){
		if(a[i]==a[x]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
