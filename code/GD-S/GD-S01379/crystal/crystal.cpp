#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[501010];
int c[501010],b[501010],lst[501010],fir[501010],sum[501010];
int maxn=0;
int find(int l,int r,int x){
	if(r<l)return l;
	int ans=0;
	int ll=l,rr=r;
	while(ll<=rr){
		int mid=ll+rr>>1;
		if(sum[r]-sum[mid-1]+m>=c[x]*(r-mid+1)){
			ans=mid;
			rr=mid-1;
		}
		else ll=mid+1;
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int tot=1;
	c[tot]=a[1];
	b[tot]=1;
	fir[tot]=1;
	lst[tot]=1;
	sum[tot]=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			tot++;
			c[tot]=a[i];
			fir[tot]=i;
		}
		b[tot]++;
		lst[tot]=i;
		sum[i]=sum[i-1]+a[i];
	}
//	for(int i=1;i<=tot;i++){
//		cout<<fir[i]<<" "<<lst[i]<<" "<<c[i]<<" "<<b[i]<<"\n";
//	}
	for(int i=1;i<=tot;i++){
		maxn=max(maxn,lst[i]-find(1LL,fir[i]-1,i)+1);
	}
	cout<<maxn;
	return 0;
}
