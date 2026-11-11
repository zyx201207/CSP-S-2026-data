#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans;
bool f[200010];
long long baoli(long long q,long long num){
	long long y=0;
	while(q>=0){
		for(long long i=n;i>=1;i--){
			if(f[i]==false){
				y=max(y,num&a[i]);
			}
		}
		q--;
		num=y;
	}
	return y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	if(n<=20){
		f[n]=true;
		ans=baoli(m,a[n]);
		printf("%lld",ans);
	}else if(n<=2000){
		if(m==1){
			printf("%lld",a[n]);
		}else if(m==2){
			for(long long i=1;i<=n;i++){
				for(long long j=1;j<=n;j++){
					if(i!=j){
						ans=max(a[i]&a[j],ans);
					}
				}
			}
			printf("%lld",ans);
		}else{
			ans=a[1];
			for(long long i=2;i<=n;i++){
				ans=ans&a[i];
			}
			printf("%lld",ans);
		}
	}else{
		if(m==1){
			printf("%lld",a[n]);
		}else if(m==2){
			for(long long i=1;i<=n;i++){
				for(long long j=1;j<=n;j++){
					if(i!=j){
						ans=max(a[i]&a[j],ans);
					}
				}
			}
			printf("%lld",ans);
		}else if(m==n){
			ans=a[1];
			for(long long i=2;i<=n;i++){
				ans=ans&a[i];
			}
			printf("%lld",ans);
		}else{
			for(long long i=n;i>=n-100;i--){
				if(a[i]==a[i]-1){
					printf("%lld",a[i]-1);
					break;
				}
			}
		}
	}
	return 0;
}
