#include<bits/stdc++.h>
using namespace std;
long long n,m,x,q,N;
struct ff{
	long long x,z[35];
};
ff a[200005];
long long cnt[35];
bool cmp(ff L,ff R){
	return L.z[q]>R.z[q];
}
long long f(long long L,long long R){
	long long da=0;
	while(L<=R){
		long long mid=(L+R)/2;
		if(a[mid].z[q]==1) da=mid,L=mid+1;
		else R=mid-1;
	}
	return da;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i].x;
	for(int i=1;i<=n;i++){
		long long x=a[i].x,l=0;
		while(x){
			cnt[l]+=x%2;
			a[i].z[l]=x%2;
			x=x/2;
			l++;
		}
	}
	N=n;
	for(int i=30;i>=0;i--){
		if(cnt[i]<m) continue;
		q=i;
		sort(a+1,a+N+1,cmp);
		long long wz=f(1,N);
		N=wz;
	}
	long long da=a[1].x;
	for(int i=2;i<=m;i++){
		da=da&a[i].x;
	}
	cout<<da;
	return 0;
}
