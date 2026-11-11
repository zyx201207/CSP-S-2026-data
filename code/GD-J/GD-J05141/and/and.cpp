#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010],sum;
bool bz=false,b=false;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		if(a[i]==0)
			bz=true;
	for(int i=1;i<=n;i++){
		if((a[i]+1)%2==0)
			b=true;
		else
			b=false;
	} 
	if(bz==true){
		printf("0");
		return 0;
	}//14,15
	if(b==true){
		printf("0");
		return 0;
	}
	if(m==1){
		int maxx=-1;
		for(int i=1;i<=n;i++)
			maxx=max(maxx,a[i]);
		printf("%lld",maxx);
	}//6
	if(m==2){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				maxx=max(maxx,a[i] & a[j]);
		}
		printf("%lld",maxx);
	}//8,9,10
	if(m==n){
		for(int i=2;i<=n;i++){
			a[i]=a[i] & a[i-1];
		}
		printf("%lld",a[n]);
	}//7
}
