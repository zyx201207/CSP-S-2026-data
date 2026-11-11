#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+1;
long long n,m,a[N],cha[N],ans=0,p;
void solve(long long l,long long r){
	p=0;
	for(long long i=l;i<=r;i++){
		p+=cha[i]-cha[r];
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++) cha[i]=a[n]-a[i];
//	for(long long i=1;i<=n;i++) cout<<cha[i]<<' ';
//	cout<<'\n';
	for(long long i=1;i<=n;i++){
		for(long long j=i;j>=1;j--){
			solve(j,i);
//			cout<<j<<' '<<i<<' '<<p<<'\n';
			if(p>m) break;
			ans=max(i-j+1,ans);
		}
	}
	cout<<ans;
	return 0;
}
