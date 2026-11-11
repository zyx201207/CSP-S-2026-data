#include<bits/stdc++.h>
using namespace std;
long long a[1000010],n,m,x,y,z,ls,lsd,da,lsj;
bool boo=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	x=1;
	y=n;
	while(x<=y){
		z=(x+y)/2;
		lsd=m;
		boo=1;
		lsj=1;
		while(a[z]==a[z-lsj]){
			lsj++;
		}
		ls=z-lsj;
		for(;ls>=0;ls--){
			lsd=lsd-a[z]+a[ls]; 
			if(lsd<0){
				y=z-lsj;
				while(a[z]==a[z+1]){
					z++;
				}
				da=max(z-ls,da);
				boo=0;
				break;
			}
		}
		if(boo){
			while(a[z]==a[z+1]){
				z++;
			}
			da=max(z,da);
			x=z+1;
		}
	}
	printf("%lld",da);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
