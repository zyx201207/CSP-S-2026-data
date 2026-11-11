#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000005],ans,rc[2000005],lc[2000005];
void initlc(int l,int r) {
	lc[l-1]=0;
//	for(int i=l;i<=)
}
void initrc(int l,int r) {
	rc[r+1]=0;
	for(int i=r;i>=l+3;i--) {
		if(x[i]-x[i-2]>d) {
			if(rc[i+1]) rc[i]=rc[i+1];
			else rc[i]=i;
		}
		else rc[i]=0;
	}
}
void work(int l,int R) {
	if(R-l<3) return;
	int mid=upper_bound(x+l+2,x+R,x[l]+d)-x-1;
	int r=upper_bound(x+mid+1,x+R+1,x[mid-1]+d)-x-1;
//	cout<<l<<' '<<mid<<' '<<r<<'\n';
	if(r>R) return;
	initrc(l,R);
	if(x[mid-1]+d>=x[r]&&x[mid-2]+d<x[r]) {
		if(rc[r]) {
			ans+=rc[r]-r+1;
			l=rc[r];
			mid=l+2;
			r=mid+1;
		}
		else ans++;
	}
	while(1) {
		do {
			l++;
			do{mid++;}while((mid<l+2||x[mid+1]-x[l]<=d)&&mid<R);
			if(x[mid]-x[l]>d) break;
			do{r++;}while(r<=R&&(r<=mid||(r<R&&x[r+1]-x[mid-1]<=d)));
			if(r>R) return;
		} while(!(x[mid-1]+d>=x[r]&&x[mid-2]+d<x[r]));
		if(x[mid]-x[l]>d) continue;
		if(rc[r]) {
			ans+=rc[r]-r+1;
			l=rc[r];
			mid=l+2;
			r=mid+1;
		}
		else ans++;
	}
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--) {
		ans=0;
		cin>>n>>d>>x[1];
		int l=1;
		for(int i=2;i<=n;i++) {
			cin>>x[i];
			if(x[i]-x[i-1]>d) {
				work(l,i-1);
				l=i;
			}
		}
		work(l,n);
		cout<<ans<<'\n';
	}
	return 0;
}
