#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=5e5+5;
ll n,m;
ll a[N];
ll qz[N];

bool check(int sum) {
	for(int i=sum; i<=n; i++) {
		int r=i-sum+1,l=i;
		ll sans=0;
		while(r<l) {
			sans+=a[l]-a[r];
			l--;
			r++;
			if(sans>m) break;
		}if(sans<=m) {
//			cout<<sum<<' '<<i-sum+1<<"~"<<i<<endl;
			return 1;
		}
	}return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("r","crystal.in",stdin);
	freopen("w","crystal.out",stdout);
	cin>>n>>m;
	if(n==1) {
		cout<<1;
		return 0;
	}
	bool flag1=1;
	for(int i=1; i<=n; i++) cin>>a[i];
	if(n==2) {
		if(abs(a[1]-a[2])<=m) cout<<2;
		else cout<<1;
		return 0;
	}
	for(int i=2; i<=n; i++)
		if(a[i]!=a[i-1]) {
			flag1=0;
			break;
		}
	if(flag1) {
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	bool flag2=1;
	ll dc=a[2]-a[1];
	for(int i=3; i<=n; i++)
		if(a[i]-a[i-1]!=dc) {
			flag2=0;
			break;
		}
	if(flag2) {
		m=m/dc;
		ll ans=1;
		for(int i=1; i; i++) {
			if(m<i) break;
			if(m<i*2) {
				ans++;
				break;
			}
			m-=i*2;
			ans+=2;
		}
		cout<<ans;
		return 0;
	}
	int r=1,l=n;
	while(r+1<l) {
		int mid=(r+l)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	cout<<r;
	return 0;
}
/*

#include<bits/stdc++.h> 
using namespace std;

#define ll long long 
const ll N=5e5+5;
ll n,m;
ll a[N];
ll ans=1;

bool cmp(ll x,ll y){
	return x>y;
}

void dfs(ll nows,ll sum,ll nowi) {
//	cout<<"dfs "<<nows<<' '<<sum<<' '<<nowi<<endl;
	if(nows==0) {
		ans=max(ans,sum);
		return ;
	}
	if(nowi>n) return ;
	if(nows<a[nowi]) {
		dfs(nows,sum,nowi+1);
		return ;
	}dfs(nows-a[nowi],sum+1,nowi+1);
	dfs(nows,sum,nowi+1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
//	freopen("r",".in",stdin);
//	freopen("w",".out",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
//		a[i]+=1000000000000;
	}
	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	for(int i=1;i<=n;i++) {
		if(n-i+1<=ans) break;
		dfs(a[i],1,i+1);
	}
//	cout<<ans<<endl;
	ans=min(ans,m);
	cout<<ans;
	return 0;
}
5 5
1 2 4 8 9
*/
