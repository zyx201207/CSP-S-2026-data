#include<bits/stdc++.h>
using namespace std;
long long a,b,c[500005],d[500005],e,f,g,h;
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	scanf("%lld %lld",&a,&b);
	for(int i=1;i<=a;i++){
		scanf("%lld",&c[i]);
	}
	sort(c+1,c+a+1);
	for(int i=1;i<=a;i++){
		d[i]=d[i-1]+c[i];
	}
	for(int i=1;i<=a;i++){
		e=0;
		f=i-1;
		while(e<=f){
			g=(e+f)/2;
			if(g*c[i]-(d[i-1]-d[i-g-1])>b){
				f=g-1;
			}
			else{
				e=g+1;
			}
		}
		h=max(h,f+1);
	}
	printf("%lld",h);
	return 0;
}
