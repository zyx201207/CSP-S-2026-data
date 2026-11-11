#include<bits/stdc++.h>
using namespace std;
long long n,a,ans=0;
char c[1000000010],x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	scanf("%lld",&n);
	long long sum=0;
	for(long long i=1;i<=n;i++){
		scanf("%lld %c",&a,&x);
		for(long long j=1;j<=a;j++){
			c[++sum]=x;
		}
	}
	if(sum%2==1){
		long long m=sum/2+1;
		for(long long l=1,r=sum;l<m,r>m;l++,r--){
			if(c[l]!=c[r]) ans++;
		}
	}else{
		long long m=sum/2;
		for(long long l=1,r=sum;l<=m,r>=m+1;l++,r--){
			if(c[l]!=c[r]) ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
