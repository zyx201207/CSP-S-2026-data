#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m;
long long a[N];
long long b[N];
int ans;
bool cmp(long long x,long long y){
	return x>y;
}
int check(int k){
	int l=k,r=n;
	int idx=k;
	while(l<=r){
		int mid=(l+r)>>1;
		long long sum=a[k]*(mid-k)-(b[mid]-b[k]);
		if(sum<=m){
			idx=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return idx-k+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ans=max(ans,check(i));
	}
	cout<<ans;
	return 0;
}