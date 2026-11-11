#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],flag1=0,d,b[500005];
int maxi=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=2;i<=n-1;i++){
		if((a[i]-a[i-1])!=(a[i+1]-a[i])){
			flag1=1;
		}
		d=a[i]-a[i-1];
	}
	b[1]=1;
	for(int i=2;i<=1000;i++){
		b[i]=b[i-1]+i;
	}
	if(flag1==0&&n>5000){
		long long tp=m/d,cnt;
		for(int i=1000;i>=1;i--){
			if(tp>=b[i]){
				cnt=i+1;
				break;
			}
		}
		printf("%lld",cnt);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		long long sum=0;
		for(int j=i;j>=1;j--){
			sum=sum+a[i]-a[j];
			if(sum>m){
				break;
			}else{
				maxi=max(maxi,i-j+1);
			}
		}
		if(i<maxi){
			break;
		}
	}
	printf("%d",maxi); 
	return 0;
}
