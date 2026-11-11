#include<bits/stdc++.h>
using namespace std;
long long n,x,c[200005];
char z[200005];
int main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&c[i],&z[i]);
	}
	bool f=1;
	for(int i=2;i<=n;i++){
		if(z[i]!=z[i-1]){
			f=0;
			break;
		}
	}
	if(f){
		printf("0");
		return 0;
	}
	int i=1,j=n;
	while(i!=j){
		if(z[i]==z[j]){
			if(c[i]>=c[j]){
				c[i]-=c[j];
				j--;
			}else{
				c[j]-=c[i];
				i++;
			}
		}else{ if(c[i]>=c[j]){			
				c[i]-=c[j];
				x+=c[j];
				j--;		
			}else{
				c[j]-=c[i];
				x+=c[i];
				i++;
			}
		}
	}
	printf("%lld",x);
	return 0;
}
