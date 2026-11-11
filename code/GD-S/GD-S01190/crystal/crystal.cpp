#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],he[500005],mans=1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		he[i]=a[i]+he[i-1];
	}
	if(n>5000){
		for(long long i=1;i<=n;i++){
			long long v=a[i]*i-he[i];
			if(v<=m) mans=i;
			 
		}
	}else{
		for(long long i=1;i<=n;i++){
			long long he11[50005]={},ans=1;
			for(long long k=1;k<=n;k++){
				he11[k]=he[k]-he[i-1];
			}
			for(long long j=i;j<=n;j++){
				long long v=a[j]*(j-i+1)-he11[j];
				if(v<=m)ans=j-i+1;
			}
			mans=max(ans,mans);
		}
	}
	printf("%lld",mans);
} 

