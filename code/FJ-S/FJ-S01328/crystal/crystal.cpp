#include<bits/stdc++.h>
using namespace std;
long long n,m;
const long long N=5e5+15;
long long a[N];
long long getabs(long long ml){
	long long sum=0; 
	for(int i=1;i<=n;i++)
		sum+=max(ml-a[i],0LL);
	return sum;
}
int main(){
	//差点关机了 
	// i wanna
	// qiao ke li zhen hao chi
	//dp? erfen
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long mi=LLONG_MAX,ma=LLONG_MIN;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mi=min(mi,a[i]);
		ma=max(ma,a[i]);
	}
	sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	//for(int i=1;i<=n;i++) a[i]-=mi;  //这里加不加无所谓 
	//long long l=0,r=ma-mi;
	long long l=mi,r=ma;
	while(l<r){
		long long mid=(l+r)/2;
		//cout<<l<<" "<<r<<" "<<mid<<" "<<getabs(mid)<<endl; 
		if(getabs(mid)<=m) l=mid+1; //getabs
		else r=mid;
	}
//	for(int i=1;i<=n;i++)
//		if(l<a[i]){
//			cout<<i-1<<endl; //再二分没用 
//			return 0;
//		}
	long long l2=0,r2=n;
	while(l2<r2){
		long long mid=(l2+r2)/2;
		if(l>=a[mid]) l2=mid+1;   //结果还是一样 
		else r2=mid;
	}
	cout<<l2-1;
	//最后一个点错了 我的：315829，源:315275 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
