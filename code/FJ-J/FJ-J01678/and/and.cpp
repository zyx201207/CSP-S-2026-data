#include<bits/stdc++.h>
using namespace std;
long long a[100005];
long long f(long long a,long long b){
	int sum=0,s=1;
	while(a!=0||b!=0){
	sum+=((a%2)&(b%2))*s;
	a/=2;
	b/=2;
	s*=2;
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(m==1){
		long long maxx=0;
		for(int i=1;i<=n;i++){
			if(a[i]>maxx)
			maxx=a[i];
		}
		printf("%lld",maxx);
		return 0;
	}
	else if(m==2){
		long long maxx=0;
		for(int j=1;j<n;j++){
			for(int j2=j+1;j2<=n;j2++){
				long long l=f(a[j],a[j2]);
				if(l>maxx)
				maxx=l;
			}
		}
		printf("%lld",maxx);
	}
	return 0; 	
}
