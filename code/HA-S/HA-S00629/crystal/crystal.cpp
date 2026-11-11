#include<bits/stdc++.h>
using namespace std;
long long n,maxx=-1e18,minn=1e18,ans=0;
long long m;
long long a[6000001];
int main(){	
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxx=max(a[i],maxx);
		minn=min(a[i],minn);
	}
	sort(a+1,a+n+1);
	if(m>1000000000){
		bool z=false;
		for(int i=1;i<=n;i++){
			if(a[i]!=i){
				z=true;
			}
			minn=min(minn,a[i]);
		}
		if(z){
			if(minn>=0){
				minn=0;
			}
			for(int i=1;i<=n;i++){
				a[i]+=abs(minn);
			}
		}
		long long anss=0,cs=0;
		for(int i=n-1;i>=0;i--){
			long long z=a[i],gs=i+1;
			if(gs%2==0){
				cs=z*(gs/2);
			}else{
				cs=z*(gs/2)+z/2;
			}
			if(cs<=m){
				anss=gs;
				break;
			}
		}
		printf("%lld",anss);
		return 0;
	}
	for(int i=minn;i<=maxx;i++){
		long long t=0;
		long long cs=m;
		long long l=0,r=n+1;
		while(l+1!=r){
			long long mid=(l+r)/2;
			if(a[mid]<=i){
				l=mid;
			}else{
				r=mid;
			}
		}
		for(int j=r-1;j>=1;j--){
			long long x=a[j];
			if(abs(i-x)>cs){
				break;
			}else{
				t++;
				cs-=abs(i-x);
			}
		}
		ans=max(ans,t);
	}
	printf("%lld",ans);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
