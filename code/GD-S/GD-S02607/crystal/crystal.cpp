#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N];
long long sum,k,ans,mx;
bool check(long long x){
	long long res=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=x) res=res+(x-a[i]);
	}
	return res<=m;
}
long long bs(long long l,long long r){
	long long mid,rt=0;
	while(l<=r){
		mid=(long long)(l+r+1)/2;
		if(check(mid)){
			rt=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return rt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	k=bs(1,mx);
	//cout<<k<<endl;
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]>k) break;
		sum=sum+(k-a[i]),ans++;
		//cout<<sum<<" ";
		if(sum>m) break;
	}
//	int mid=a[n/2],k1=a[n/2+1],k2=a[n/2-1];
//	
//	for(int i=1;i<=n;i++){
//		if(a[i]<=mid) res+=(ll)abs(mid-a[i]),cnt1++;
//		if(res>m) break;cnt1--;
//	}
//	ans=cnt1;
//	if(res<=m){
//		long long cnt2=0;
//		for(int i=n/2+1;i<=n;i++){
//			res+=(ll)(i-1)*(a[i]-mid);
//			if(res>m) break;
//			cnt2=i;
//			mid=a[i];
//		}
//		long long op=max(cnt1,cnt2);
//		ans=max(ans,op);
//	}
//	
//	res=0,cnt1=0;
//	for(int i=1;i<=n;i++){
//		if(a[i]<=k1) res+=(ll)abs(k1-a[i]),cnt1++;
//		if(res>m) break;cnt1--;
//	}
//	ans=max(ans,cnt1);
//	if(res<=m){
//		long long cnt2=0;
//		for(int i=n/2+2;i<=n;i++){
//			res+=(ll)(i-1)*(a[i]-k1); 
//			if(res>m) break;
//			cnt2=i;
//			k1=a[i];
//		}
//		long long op=max(cnt1,cnt2);
//		ans=max(ans,op);
//	}
//	
	cout<<ans;
	return 0;
}
