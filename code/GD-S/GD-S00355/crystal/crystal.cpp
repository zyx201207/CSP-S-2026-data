#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using Int=ll;
const int N=5e5+10;
ll a[N],c[N],lst[N];
Int sum[N];
inline void merge(int l1,int r1,int r2){
	int st=l1-1,l2=r1+1,k=0;
	while(l1<=r1&&l2<=r2)
		if(a[l1]>a[l2])c[++k]=a[l1++];
		else c[++k]=a[l2++];
	while(l1<=r1)c[++k]=a[l1++];
	while(l2<=r2)c[++k]=a[l2++];
	for(int i=1;i<=k;++i)
		a[st+i]=c[i];
}
void mergesort(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1;
	mergesort(l,mid);
	mergesort(mid+1,r);
	merge(l,mid,r);
}
int n,ans;
int main(){
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	mergesort(1,n);
	a[n+1]=-1e18-1;
	for(int i=1;i<=n;++i){
		c[i]=c[i-1]+a[i]-a[i+1];
		sum[i]=sum[i-1]+c[i];
	}
	for(int i=1,l,r,mid;i<=n;++i){
//		for(int j=1;j<=n;++j)cout<<(sum[j]-(a[1]-a[i])*(j-i+1)-sum[i-1])<<' ';
//		lst[i]=(a[1]-a[i+1])+lst[i-1];
//		cout<<lst[i-1];
//		cout<<'\n';
		l=1;
		r=n;
		while(l<r){
			mid=(l+r+1)>>1;
			if(sum[mid]-(a[1]-a[i])*(mid-i+1)-sum[i-1]<=m)l=mid;
			else r=mid-1;
		}
		ans=max(ans,l-i+2);
	}
	cout<<ans;
	return 0;
}
