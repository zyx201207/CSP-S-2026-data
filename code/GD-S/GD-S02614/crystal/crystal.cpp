#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+101;
long long n,m,a[N],l,r,mid,ans=1;
priority_queue<long long,vector<long long>,greater<long long> > q;
bool check(long long x){
	long long sum=0,w,mn=N;
	for(long long i=x;i<=n;i++){
		sum=0;
		w=a[i];
		for(long long j=i-x+1;j<=i;j++){
			sum+=w-a[j]; 
		}
		mn=min(mn,sum);
	}
	return mn<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	l=1,r=n+1;
	while(l<=r){
		mid=l+(r-l)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%lld",ans);
	return 0;
}
