#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int n,ans=-5e5;
long long m,a[N],dt[4*N],d[N],f[4*N];
void build(int p,int s,int t){
	if(s==t){
		dt[p]=d[s];
		return;
	} 
	int mid=(s+t)>>1;
	build(2*p,s,mid);
	build(2*p+1,mid+1,t);
	dt[p]=dt[2*p]+dt[2*p+1];
}
void update_lazy(int p,int s,int t){
	if(f[p]){
		dt[p]+=(t-s+1)*f[p];
		if(s!=t){
			f[2*p]+=f[p];
			f[2*p+1]+=f[p];	
		}
		f[p]=0;
	}
}
long long getsum(int p,int s,int t,int l,int r){
	update_lazy(p,s,t);
	if(l>t||r<s) return 0;
	if(l<=s&&t<=r) return dt[p];
	int mid=(s+t)>>1;
	long long ls=getsum(2*p,s,mid,l,r);
	long long rs=getsum(2*p+1,mid+1,t,l,r);
	return ls+rs;
}
void update(int p,int s,int t,int l,int r,long long v){
	update_lazy(p,s,t);
	if(l>t||r<s) return;
	int mid=(s+t)>>1;
	if(l<=s&&t<=r){
		dt[p]+=(t-s+1)*v;
		if(s!=t){
			f[2*p]+=v;
			f[2*p+1]+=v;
		} 
		return;
	}
	update(2*p,s,mid,l,r,v);
	update(2*p,mid+1,t,l,r,v);
	dt[p]=dt[2*p]+dt[2*p+1];
}
int check(int l,int r){
	int left=l,right=r,mid=(l+r)>>1,cnt=0;
	long long mtmp=m;
	while(left<right){
		mid=(left+right)>>1;
		long long gm=getsum(1,1,n-1,mid+1,right);
		if(gm>mtmp) left=mid;
		else{
			cnt+=right-mid;
			mtmp-=gm;      
			right=mid;                
		}
	}
	return cnt;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i<n) d[i]=a[n]-a[i];
	}
	build(1,1,n-1);
	for(int i=n-1;i>=1;i--){
		ans=max(ans,check(1,i));
		update(1,1,n-1,1,i,-d[i]);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//5 8
//-3 -1 2 2 7
//5 5
//1 2 4 8 9
