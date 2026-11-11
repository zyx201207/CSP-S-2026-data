#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define endl '\n'
using namespace std;
const int N=5e5+5;
ll n,m,a[N],s[N],ans=0;
ll get(ll l,ll r){
	return a[r]*(r-l+1)-(s[r]-s[l-1]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	ll l=1,r=1;
	while(r<n){
		if(get(l,r+1)<=m) r++;
		else break;
	}
	while(r<=n){
		while(get(l,r)>m)
			l++;
		ans=max(ans,r-l+1);
		r++;
	}
	cout<<ans;
	return 0;
}
