#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,mu[111111],ans=0,z=1,d,sz=0;
	char c[111111],a,b;
	cin>>n;
	d=n;
	for(long long i=1;i<=n;i++){
		cin>>mu[i]>>c[i];
		sz+=mu[i];
	}for(long long i=1;i<=sz/2&&z<d;i+=min(mu[z],mu[d])){
		//cout<<z<<' '<<mu[z]<<' '<<d<<' '<<mu[d]<<endl;
		if(mu[z]==0) z++;
		if(mu[d]==0) d--;
		a=c[z];
		b=c[d];
		long long zz=min(mu[z],mu[d]);
		if(a!=b) ans+=zz;
		mu[z]-=zz;
		mu[d]-=zz;
		//cout<<z<<' '<<d<<' '<<a<<' '<<b<<' '<<ans<<endl;
	}cout<<ans;
	return 0;
}

