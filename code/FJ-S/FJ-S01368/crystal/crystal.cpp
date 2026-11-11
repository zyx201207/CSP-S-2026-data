#include<iostream>
#include<algorithm>
using namespace std;
long long a[500050];
long long pre[500050];
long long n,m;
long long f(long long x){
	long long l=1,r=x,mid;
	while(l<r){
		mid=(l+r)/2;
//		cout<<l<<' '<<r<<' '<<mid<<' '<<(x-mid+1)*a[x]-(pre[x]-pre[mid-1])<<endl;
		if((x-mid+1)*a[x]-(pre[x]-pre[mid-1])<=m)r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		long long nw=f(i);
//		cout<<nw<<endl;
		ans=max(ans,i-nw+1);
	}
	cout<<ans;
} 
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7*/
