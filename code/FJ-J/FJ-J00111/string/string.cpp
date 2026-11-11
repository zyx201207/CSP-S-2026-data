#include<stdio.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N];
char c[N];
int m=0;
inline ll min_(ll a,ll b){
	return a<b?a:b;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int xa;
		char xc;
		scanf("%d %c",&xa,&xc);
		if(m==0||xc!=c[m]){
			m++;
			a[m]=xa;
			c[m]=xc;	
		}else{
			a[m]+=xa;
		}
	}
	int i=1,j=m;
	ll ans=0;
	while(i<j){
		if(c[i]!=c[j]){
			ans+=min_(a[i],a[j]);
		}
		if(a[i]>a[j]){
			a[i]-=a[j];	
			a[j]=0;
			j--;
		}else if(a[i]<a[j]){
			a[j]-=a[i];	
			a[i]=0;
			i++;
		}else{
			a[i]=0;
			a[j]=0;
			i++;
			j--;
		}
	}
	printf("%lld",ans);
}
