#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N],d[N],f[N];
bool check(int x){
	for(int i=x;i<=n;i++){
		long long k=f[i]-f[i-x+1]-(d[i]-d[i-x+1])*(i-x);
		if(k<=m) return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	d[1]=0;
	f[1]=0;
	for(int i=2;i<=n;i++){
		d[i]=d[i-1]+(a[i]-a[i-1]);
		f[i]=f[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
