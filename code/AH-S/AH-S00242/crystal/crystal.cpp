#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int n,zt,ans;
long long int m;
long long int a[N];

bool pd(int x){
	long long int sum=0,mins=WINT_MAX;
	for(int i=x;i<=n;i++){
		sum=0;
		for(int j=i-1;j>=i-x+1;j--)sum+=a[i]-a[j];
		mins=min(mins,sum);
	}
	if(mins<=m)return true;
	return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i>=3)if(a[i]-a[i-1]!=a[2]-a[1])zt=1;
	}
	if(!zt){
		m/=(a[2]-a[1]);
		m*=2;
		long long int sqr=sqrt(m);
		if(sqr*(sqr+1)<=m)printf("%lld",sqr+1);
		else printf("%lld",sqr);
		return 0;
	}
	sort(a+1,a+1+n);
	int left=1,right=n;
	while(left<=right){
		int mid=(left+right)/2;
		if(pd(mid))ans=mid,left=mid+1;
		else right=mid-1;
	}
	printf("%d",ans);
	return 0;
}
