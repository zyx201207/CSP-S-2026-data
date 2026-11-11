#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long a[N],sum[N];
int n,m;

bool check(int mle){
	long long mn=1e18+10000,l,r;
	for(int i=mle;i<=n;i++){
		int x=sum[i]-sum[i-mle];
		if(mn>x) mn=x,l=i-mle+1,r=i;
	}
	long long mx=0;
	for(int i=l;i<=r;i++){
		mx=max(mx,a[i]);
	}
	if(mx*mle-mn>m) return 0;
	else return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<1; return 0;
	}
	int flag=1;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=i) flag=0;
	}
	if(flag){
		int ans=1,sum=1;
		while(m>=sum){
			sum+=++ans;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n+1;
	while(l<r){
		int mle=l+r>>1;
		if(check(mle)) l=mle+1;
		else r=mle;
	}
	cout<<r-1;
	return 0;
}
