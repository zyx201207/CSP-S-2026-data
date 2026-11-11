#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7;
ll n, m, a[N], tmp[N], d[N], ans=1;
unsigned ll prs[N];
void Merge(ll *sq, int l, int r, ll *c) {
	int mid=(l+r)>>1, i=l, j=mid+1, k=l;
	while(i<=mid && j<=r)
		if(a[j]<a[i]) c[k++]=sq[j++];
		else c[k++]=sq[i++];
	for(; i<=mid; ) c[k++]=sq[i++];
	for(; j<=r; ) c[k++]=sq[j++];
}
void Merge_Sort(ll *sq, int l, int r) {
	if(r-l<1) return;
	int mid=(l+r)>>1;
	Merge_Sort(sq, l, mid);
	Merge_Sort(sq, mid+1, r);
	Merge(sq, l, r, tmp);
	for(int i=l; i<=r; i++) sq[i]=tmp[i];
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i=1; i<=n; i++)
		scanf("%lld", &a[i]);
	Merge_Sort(a, 1, n);
	for(int i=2; i<=n; i++)
		d[i]=a[i]-a[i-1], prs[i]=prs[i-1]+d[i];
	for(ll l=1, r=1, sum=0; r<n; ) {
		r++, sum+=d[r]*(r-l);
		while(sum>m) sum-=(prs[r]-prs[l]), l++;
		ans=max(ans, r-l+1);
	}
	printf("%lld", ans);
	return 0;
}
