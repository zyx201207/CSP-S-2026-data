#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s,maxx,v[500005],h,maxi,minn=1e18;
bool f=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n-1;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i]) f=1;
	}
	if(f==0){
			for(int i=1;i<=n/2;i++) {
				if(s+i*2*(a[2]-a[1])<=m) s+=i*2*(a[2]-a[1]),maxx+=2;
				else {
					if(s+i<=m) maxx++;
					break;
				}
			}
		cout<<maxx;
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long h=0;
		for(int j=1;j<=n;j++){
			h+=abs(a[j]-a[i]);	
		}
		if(h<minn) minn=h,maxi=i;
	}
	long long x=m;
	s=0;
	for(int k=1;k<=n;k++){
		v[k]=abs(a[k]-a[maxi]);	
	}	
	sort(v+1,v+1+n);
	for(int k=1;k<=n;k++){
		if(x>=v[k]) x-=v[k],s++;
		else break;
	}
	maxx=max(maxx,s);
	cout<<maxx;
	return 0;
} 
