#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=5e5;
long long a[maxn+5];
long long b[maxn+5],d[maxn+5];
long long sum[maxn+5],sum2[maxn+5];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n ;i++){
		d[i]=a[i]-a[i-1];
		if(i==1) d[i]=0;
		b[i]=b[i-1]+(i-1)*d[i];
		sum[i]=sum[i-1]+d[i];
		sum2[i]=sum2[i-1]+sum[i];
	}
	int l=1,r=1,ans=0;
	while(l<=n && r<=n){
		if(b[r]-(l-1)*sum[r]+sum2[l-1]<=m){
			ans=max(ans,r-l+1);
			r++;
		}
		else l++;
	} //保佑这个不挂 
	cout<<ans;
	return 0;
}//Expect: 100 pts
