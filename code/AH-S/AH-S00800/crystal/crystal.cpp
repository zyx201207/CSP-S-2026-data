#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[500005],cnt=0,zans=0;
bool check1(){
	for(long long i=1;i<=n;i++){
		if(a[i]!=i)return 0;
	}
	return 1;
}
bool check2(){
	long long t=a[2]-a[1];
	for(long long i=3;i<=n;i++){
		if(a[i]-a[i-1]!=t)return 0;
	}
	return 1;
}
bool check(long long mid){
	long long ans=0;
	for(long long i=1;i<=n;i++){
		if(a[i]>=a[mid])break;
		ans+=a[mid]-a[i];
	}
	return ans<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long l=1,r=n;
	if(check1()){
		for(long long i=1;i<n;i++){
			if(m>=i)cnt++;
			m-=i;
		}
		cout<<cnt+1;
		return 0;
	}
	else if(check2()){
		long long l=a[2]-a[1];
		for(long long i=l;i<n*l;i+=l){
			if(m>=i)cnt++;
			m-=i;
		}
		cout<<cnt+1;
		return 0;
	}
	sort(a+1,a+n+1);
	long long ans=1;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}
		else r=mid-1;
	}
	for(long long i=1;i<=n;i++){
		if(a[i]<=a[ans])zans++;
	}
	cout<<zans;
//	long long t=a[n/2],sum=0;
//	cout<<t<<endl;
//	for(long long i=0;i<n;i++){
//		if(t-a[i]<0)a[i]=a[i]-t;
//		else a[i]=t-a[i];
//		sum+=a[i];
//	}
//	sort(a,a+n);
//	for(long long i=0;i<n;i++){
//		if(m>=a[i])ans++;
//		m-=a[i];
//	}
//	for(int i=0;i<n;i++)cout<<a[i]<<" ";
//	cout<<ans<<" "<<sum;
	return 0;
}
