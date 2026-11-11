#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],p[500010],s[500010];
bool isA(){
	for(int i=1;i<=n;i++){
		if(a[i]!=i) return false;
	}
	return true;
}
bool isB(){
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			return false;
		}
	}
	return true;
}
bool check(long long x){
	for(int i=x+1;i<=n;i++){
		long long l=i-x,r=x;
		long long ss=a[i]*x-(s[r]-s[l-1]);
		if(ss<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	if(m==0){
		long long num=0,ma=-1;
		for(int i=1;i<=n-1;i++){
			if(a[i+1]!=a[i]){
				num=0;
			}else{
				num++;
			}
			ma=max(num,ma);
		}
		cout<<ma+1;
		return 0;
	}
	if(isA()){
		for(long long i=0;i<=n+1;i++){
			p[i]=(i*i+i)/2;
		}
		if(m==0){
			printf("0");
			return 0;
		}
		if(m>=((n-1)*(n-1)+n-1)/2){
			printf("%lld",n);
			return 0;
		}
		for(long long i=0;i<=n-1;i++){
			if(m==p[i]||(m>p[i]&&m<p[i+1])){
				printf("%lld",i+1);
				return 0;
			}
		}
		return 0;
	}
	if(isB()){
		for(long long i=0;i<=n+1;i++){
			p[i]=(i*i+i)/2;
		}
		if(m==0){
			printf("0");
			return 0;
		}
		if((m>=(n-1)*(n-1)+n-1)/2*(a[2]-a[1])){
			printf("%lld",n);
			return 0;
		}
		for(long long i=0;i<=n-1;i++){
			if(m==p[i]*(a[2]-a[1])||(m>p[i]*(a[2]-a[1])&&m<p[i+1]*(a[2]-a[1]))){
				printf("%lld",i+1);
				return 0;
			}
		}
		return 0;
	}
	if(n<=5000){
		long long ans=-1;
		for(int i=1;i<=n;i++){
			long long cnt=1,m1=m,j;
			for(j=i-1;j>=1;j--){
				if(m1-(a[i]-a[j])<0){
					break;
				}
				m1-=a[i]-a[j];
				cnt++;
			}
			ans=max(cnt,ans);
		}
		printf("%lld",ans);
		return 0;
	}
	long long l=0,r=n,cnt=0;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			cnt=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<cnt+1;
	return 0;
} 
