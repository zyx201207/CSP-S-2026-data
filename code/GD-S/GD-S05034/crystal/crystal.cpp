#include<bits/stdc++.h>
using namespace std;
long long m,n,k,z,ans=0;
long long a[500007];
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m<=1000000000){
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		k=m;
		z=1;
		while(z*(a[i+z]-a[i+z-1])<=k){
			if(i+z>n) break;
			k-=z*(a[i+z]-a[i+z-1]);
			z++;
		}
		ans=max(z,ans);
	}
	cout<<ans;
	}
	else{
		long long d=a[2]-a[1];
		long long i=1;
		if(d>m){
			cout<<1;
		}
		else{
			while((i+1)*i*d/2<=m){
				i++;
			}
			cout<<i;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
