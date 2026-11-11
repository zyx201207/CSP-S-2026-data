#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N=2e6+7;
int c,t,n;
ll d,x[N],ans;
ll a[N];

ll f(ll x[],int st,int ed) {
	ll ans=0;
	if(st==ed) return 0;
	int n;
	for(int i=st,j=1;i<=ed;j++,i++) {
		a[j]=x[i];
		if(i==ed) n=j;
	}
//	dp[1]=1;
	for(int i=2;i<=n;i++) {
		int cnt=0;
		for(int j=i;j>=1;j--) {
			if(a[i]-a[j]<=d) cnt++;
		}
		if(cnt>=2) ans++;
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		for(int i=1;i<=n;i++) {
			cin>>x[i];
		}
		for(int st=1;st<n;st++) {
			//choose every start point
			ans+=f(x,1,st);
			ans+=f(x,st,n);
		}
		cout<<ans<<'\n';
	}
	return 0;
}