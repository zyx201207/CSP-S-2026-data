#include<cstdio>
#include<algorithm>
using namespace std;
const int xn=5e5+5;
int n;
long long m,a[xn],maxx;
bool B=true;
long long max(long long x,long long y){
	return x>y?x:y; 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]) B=false;
	}
	if(B){
		for(int i=1;i<=n;i++){
			m-=i*(a[2]-a[1]);
			if(m<0){
				printf("%d",i);
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		long long tmp=m;
		int j=i-1;
		for(;j;j--){
			if(tmp<a[i]-a[j]){
				maxx=max(maxx,i-j);
				break; 
			}
			tmp-=a[i]-a[j];
		}
		if(!j) maxx=max(maxx,i);
	}
	printf("%lld",maxx);
	return 0;
}
