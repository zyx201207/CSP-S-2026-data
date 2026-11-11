#include <bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m,ans,bj1,bj2;
long long a[N],b[N],c[N];
long long solve(long long now){
	long long x=lower_bound(a+1,a+1+n,now)-a-1;
	long long y=upper_bound(a+1,a+1+n,now)-a;
	long long sum=y-x-1;
	if(x==0) return sum;
	long long t=m;
	while(t>=now-a[x]&&x>=1){
		sum+=1;
		t=t-(now-a[x]);
		x-=1;
		if(x<=0) break;
	}
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i=i+1) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i=i+1){
		if(a[i]!=i){
			bj1=1;
			break;
		}
	}
	if(bj1==0){
		for(int i=1;i<=n;i=i+1) b[i]=i-1;
		for(int i=1;i<=n;i=i+1) c[i]=c[i-1]+b[i];
		long long x=lower_bound(c+1,c+1+n,m)-c-1;
		cout<<x<<endl;
		return 0;
	}
	for(int i=1;i<=n-2;i=i+1){
		if(a[i+1]-a[i]!=a[i+2]-a[i+1]){
			bj2=1;
			break;
		}
	}
	if(bj2==0){
		for(int i=1;i<=n;i=i+1) c[i]=c[i-1]+(a[2]-a[1]);
		long long x=lower_bound(c+1,c+1+n,m)-c-1;
		cout<<x<<endl;
		return 0;
	}
	for(int i=2;i<=n;i=i+1){
		long long f=solve(a[i]);
		ans=max(ans,f);
	}
	cout<<ans<<endl;
	return 0;
}
/*
7 5
1 5 10 15 20 25 30

65
*/
