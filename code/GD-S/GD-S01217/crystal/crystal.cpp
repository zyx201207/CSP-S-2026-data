#include<bits/stdc++.h>
#define int long long
int a[500005],n,m,ans,sm[500005];
bool chk(int len,int base){
//	for(int l=1;l<=base-len+1;l++){
//		int r=l+len-1;
//		int c=sm[r]-sm[l-1];
//		
//	}
	if(base<len)return false;
	int t=sm[base]-sm[base-len];
	int s=a[base]*len;
//	printf("*** len=%lld base=%lld t=%lld s=%lld t+m=%lld\n",len,base,t,s,t+m);
	return (t+m)>=s;
}
int binary_search(int base){
	int l=1,r=n,ans=-1;
	while(l<=r){//枚举区间长度 
		int mid=(l+r)/2;
		if(chk(mid,base)){
//			printf("***TRUE mid=%lld\n",mid);
			ans=std::max(ans,mid);
			l=mid+1;
		}else r=mid-1;
	}
	return ans;
}
signed main(){
	std::freopen("crystal.in","r",stdin);
	std::freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sm[i]=sm[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ans=std::max(binary_search(i),ans);
	}
	printf("%lld\n",ans);
	return 0;
}
