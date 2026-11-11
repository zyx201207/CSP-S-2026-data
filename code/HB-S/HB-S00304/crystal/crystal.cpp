#include <bits/stdc++.h>
using namespace std;
//based 1
long long n,m;
long long arr[(int)5e5+10];
long long diff[(int)5e5+10];
long long ans,sum;

void init(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
		diff[i]=arr[i]-arr[i-1];
		sum+=(i-1)*(arr[i]-arr[i-1]);
	}
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	init();
	stable_sort(arr+1,arr+n+1);
	if(n<=5000){
		for(int i=1;i<=n;i++){
		long long sum=0,num=0;
			for(int j=i+1;j<=n;j++){
				sum+=(arr[j]-arr[j-1])*(num+1);
				if(sum>m) break;
				else num++;
			}
			ans=max(num+1,ans);
		}
		printf("%lld",ans);
		return 0;
	}
	long long diffcom=arr[2]-arr[1];
	long long k=m/diffcom;
	long long nn=1;
	ans=1;
	while(nn<=k){
		if(nn+ans+1<=k){
			
			nn+=ans+1;ans++;
			//cout<<nn<<" "<<ans<<endl;
		}else break;
	}
	printf("%lld",ans+1);
	return 0;
}
