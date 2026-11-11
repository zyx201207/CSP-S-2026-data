#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],l,r,ans,cnt,mx,s,v[500010];
void ms(int l,int r){
	if(l==r) return;
	int mid=l+(r-l)/2;
	ms(l,mid),ms(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r){
		if(a[i]>a[j]) v[k++]=a[j++];
		else v[k++]=a[i++];
	}
	if(i>mid)while(j<=r) v[k++]=a[j++];
	else while(i<=mid) v[k++]=a[i++];
	for(int o=l;o<=r;++o) a[o]=v[o];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	ms(1,n);
	l=1ll,r=2ll;
	ans=1ll,cnt=0ll,s=1ll;mx=a[1];
	while(r<=n){
		while(cnt+s*(a[r]-mx)>m){
			cnt-=a[r-1]-a[l];
			l++,s--;
		}
		s++;
		ans=max(ans,s);
		cnt+=(s-1)*(a[r]-mx);
		mx=a[r];
		r++;
	}
	cout<<ans;
	return 0;
}
