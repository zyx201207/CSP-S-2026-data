#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	long long sum=0;
	int r=n,ans=0;
	for(int i=1;i<=n;++i){
		long long x=(a[i]-a[i-1])*(i-1);
		if(sum>m-x){
			r=i-1;
			break;
		}
		sum+=x;
	}
	ans=max(ans,r);
	int p=1;
	long long cnt=0; 
	for(int i=r+1;i<=n;++i){
		long long x=(a[i]-a[i-1])*(i-p);
		while(sum>m-x){
			sum-=a[i+1]-a[p];
			p++;
		}
		ans=max(ans,i-p+1); 
		sum+=x;
	}
	printf("%d",ans);
    return 0;
}
/*
8 10
1 2 4 8 9 10 13 15 





*/
