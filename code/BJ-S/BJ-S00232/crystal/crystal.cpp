#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long b[500005];
long long l,r;
long long val;
long long ans;
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+1+n);
	l=1,r=1;
	while(r<=n){
		ans=max(ans,r-l+1);
		r++;
		val+=(r-l)*(a[r]-a[r-1]);
		while(val>m){
			val-=a[r]-a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
