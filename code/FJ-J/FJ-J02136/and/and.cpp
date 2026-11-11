#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],sum,maxn=-1e9;
bool pd(int x){
	int s=0,xx=x;
	while(xx!=1){
		xx/=2;
		s++;
	}
	long long sum1=1;
	for(int j=1;j<=s;j++) sum1*=2;
	if(sum1==x) return true;
	return false; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	sum=a[1];
	if(m==1){
		cout<<a[n];
		return 0;
	} 
	if(m==2){
		for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) maxn=max(maxn,a[i]&a[j]);
		cout<<maxn;
		return 0;
	}
	if(m==n){
		for(int i=2;i<=n;i++) sum&=a[i];
		cout<<sum;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			sum=a[1];
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				sum&=a[i];
			}
			maxn=max(maxn,sum);
		}
		cout<<maxn;
		return 0;
	}
	bool t=true;
	for(int i=1;i<=n;i++) if(!pd(a[i]+1)) t=false;
	if(t){
		cout<<a[n-m+1];
		return 0;
	}
	bool tt=true;
	for(int i=1;i<=n;i++) if(a[i]>=4) tt=false;
	if(tt){
		long long sum0=0,sum1=0,sum2=0,sum3=0; 
		for(int i=1;i<=n;i++){
			if(a[i]==0) sum0++;
			if(a[i]==1) sum1++;
			if(a[i]==2) sum2++;
			if(a[i]==3) sum3++;
		}
		if(m<=sum3) cout<<3;
		if(m>sum&&m<=sum2+sum3) cout<<2;
		if(m>sum2+sum3&&m<=sum1+sum2+sum3) cout<<1;
		if(m>sum1+sum2+sum3) cout<<0;
		return 0;
	}
	return 0;
}

