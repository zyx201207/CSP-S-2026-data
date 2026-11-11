#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1;
long long a[5000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	long long f=0,de=a[2]-a[1];
	for(long long i=3;i<=n;i++){
		if(a[i]-a[i-1]!=de){
			f=1;
			break;
		}
	}
	if(f==1){
		for(long long i=2;i<=n;i++){
			long long money=m,j=i-1,num=1;
			while(a[i]-a[j]<=money&&j>=1){
				money-=a[i]-a[j];
				j--;
				num++;
			}
			ans=max(num,ans);	
		}
		printf("%lld",ans);
	}else if(f==0){
		long long money=m,j=n-1,num=1;
		while(a[n]-a[j]<=money&&j>=1){
			money-=a[n]-a[j];
			j--;
			num++;
		}
		printf("%lld",num);
	}
	return 0; 
}  
