#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+10,maxm=1e9; 
int n,m;
int a[maxn],d[maxn],dp[maxm];
int ans1=-1;
int A(int x){
	int num=sqrt(x);
	if(num*num==x){
		return num-1;
	}
	else if((num+1)*num<=x){
		return num;
	}
	else{
		return num-1;
	}
}
int b(int x,int cha){
	int i=1;
	for(i=1;i*(i+cha)<=x;i++){
	}
	return i-1;
}
void f(int i){
	int c[maxn],cnt=1;
	
	for(int j=0;j<=m;j++){
		dp[j]=1;
	}
	for(int j=1;j<i;j++){
		c[j]=a[i]-a[j];
		for(int z=m;z>=c[i];z--){
			dp[z]=max(dp[z],dp[z-c[i]]+1);
		}
	}
	for(int j=0;j<=m;j++){
		ans1=max(ans1,dp[j]);
	}
	
	return;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	bool is_A=1,is_b=1,cha;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		d[i]=a[i]-a[i-1];
		if(i==1){
			cha=d[i];
		}
		else if(d[i]!=cha){
			is_b=0;
		}
		if(d[i]!=1){
			is_A=0;
		}
	}
	if(is_A){
		printf("%lld",min(A(2*m)+1,n));
		return 0;
	}
	else if(is_b){
		printf("%lld",b(2*m,cha)+1);
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		f(i);
	}
	printf("%lld",ans1);
	return 0;
}
