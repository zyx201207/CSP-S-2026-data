#include<bits/stdc++.h>
using namespace std;
const int N=2000010;
long long x[N];
int a[N],v[N],sl[N],sr[N],ssl[N],ssr[N],vv[N];
void solve(int c){
	int n;
	long long d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		v[i]=0;
		vv[i]=0;
	}
	for(int i=1;i<n;i++){
		int r=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
		int l=lower_bound(x+1,x+n+1,x[i+1]-d)-x;
		if(l<i&&r>i+1&&x[i+2]-x[l]>d&&x[r]-x[i-1]>d)vv[l]=1,v[i-1]=2,v[i+2]=1,a[l]=r-l,ssl[l]=i-l-1,ssr[l]=r-i-2;
	}
	long long ans=0;
	int ll=0;
	for(int i=1;i<=n;i++){
		sl[i]=i-ll;
		if(v[i]==2||x[i+1]-x[i]>d){
			ll=i;
		}
	}
	ll=n+1;
	for(int i=n;i>=1;i--){
		sr[i]=ll-i;
		if(v[i]==1||x[i]-x[i-1]>d){
			ll=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(vv[i]==1)ans+=(sl[i]+ssl[i])*(sr[i+a[i]]+ssr[i]);
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve(c);
	}
}
