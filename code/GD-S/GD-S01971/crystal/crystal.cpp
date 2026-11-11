#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500010;
int n;
ll m,a[N],aa[N];
struct node {
	int l,r;
	ll mx;
} tr[N<<2];
void up(int k) {
	tr[k].mx=max(tr[k*2].mx,tr[k*2+1].mx);
}
void build(int k,int l,int r) {
	tr[k].l=l,tr[k].r=r;
	if(l==r) {
		tr[k].mx=a[l];
		return;
	}
	int mid=l+r>>1;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	up(k);
}
ll find(int k,int l,int r) {
	int L=tr[k].l,R=tr[k].r;
	if(l<=L&&R<=r)return tr[k].mx;
	ll sum;
	int mid=L+R>>1;
	if(l<=mid)sum=find(k*2,l,r);
	if(r>mid)sum=max(sum,find(k*2+1,l,r));
	return sum;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int f=1;
	for(int i=1; i<=n; i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		aa[i]=aa[i-1]+a[i];
		if(a[i]!=a[i-1]+1)f=0;
	}
	if(f) {
		for(int i=n; i>=1; i--) {
			int len=i;
			int u=i;
			if(len*u<=m+aa[i]) {
				cout<<len<<endl;
				break;
			}
		}
		return 0;
	}
	int ans=1;
	if(m>1e9) {
		for(int i=1; i<=n; i++) {
			int j=n;
			while(i<=j) {
				int len=j-i+1;
				if(len<=ans)break;
				int u=max(a[i],a[j]);
				if(len*u<=m+aa[j]-aa[i-1]) {
					ans=len;
					break;
				}
				j--;
			}
		}
	} else {
		build(1,1,n);
		for(int i=1; i<=n; i++) {
			int j=n;
			while(i<=j) {
				int len=j-i+1;
				if(len<=ans)break;
				int u=find(1,i,j);
				if(len*u<=m+aa[j]-aa[i-1]) {
					ans=len;
					break;
				}
				j--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 5
8 1 2 9 4

5 8
2 7 -3 -1 2

5 8
3 4 5 1 2
*/
