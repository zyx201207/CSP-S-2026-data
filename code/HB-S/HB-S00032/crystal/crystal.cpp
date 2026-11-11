#include<bits/stdc++.h>
using namespace std;
long long n,m,l,r,mid,ans=0;
long long a[500010],q[500010],maxn=0,minn=1e12+1;
int qz(long long x,long long y){
	return q[x]-q[y]-1ll*(y-x)*(maxn-a[y-1]);
}bool chat(){
	for(int i=0;i<=n-mid;i++){
		if(qz(i,i+mid)<=m) return true;
	}return false;
}int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	l=0;
	r=n;
	for(int i=0;i<n;i++) cin>>a[i],maxn=max(maxn,a[i]);
	sort(a+0,a+n);
	q[n-1]=0;
	for(int i=n-2;i>=0;i--) q[i]=q[i+1]+maxn-a[i];
	while(l<=r){
		mid=(l+r)/2;
		if(chat()){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}cout<<ans;
	return 0;
}
