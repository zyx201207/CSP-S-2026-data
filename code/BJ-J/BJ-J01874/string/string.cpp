#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,c[200005];
char s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%s",&a[i],&s);
		c[i]=s;
	}
	long long zs=a[1],z=1,ys=a[n],y=n;
	while(666){
		if(zs>=ys){
			if(c[z]!=c[y])ans+=ys;
			zs-=ys;
			ys=0;
		}else {
			if(c[z]!=c[y])ans+=zs;
			ys-=zs;
			zs=0;
		}
		if(ys==0){
			y--;
			ys=a[y];
		}
		if(zs==0){
			z++;
			zs=a[z];
		}
		if(z>=y)break;
		//cout<<zs<<" "<<z<<" "<<ys<<" "<<y<<endl;
	}
	cout<<ans;
	return 0;
}
