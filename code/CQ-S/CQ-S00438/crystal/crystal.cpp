#include<bits/stdc++.h>
using namespace std;
long long arr[500005];
long long presum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,x,y;
	int ans=0;
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<(int)n;i++)scanf("%lld",&arr[i]);
	sort(arr,arr+n);
	for(int i=1;i<=(int)n;i++)presum[i]=presum[i-1]+arr[i-1];
	if(n<=5000){
//		for(int i=1;i<=(int)n;i++)printf("%lld ",presum[i]);
		for(int i=0;i<(int)n-1;i++){
			for(int j=i+1;j<(int)n;j++){
				x=presum[j+1]-presum[i]+m;
				y=arr[j]*(j-i+1);
				if(x>=y)ans=max(ans,j-i+1);
//				printf("%lld %lld\n",x,y);
			}
		}
	}
	bool flag=true;
	long long d=arr[1]-arr[0];
	for(int i=2;i<(int)n;i++)if(arr[i]-arr[i-1]!=d)flag=false;
	d=abs(d); 
	if(flag){
		for(int i=1;i<=(int)n;i++){
			x=d*i*(i-1)/2LL;
			if(x>m){
				ans=i-1;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
} 
