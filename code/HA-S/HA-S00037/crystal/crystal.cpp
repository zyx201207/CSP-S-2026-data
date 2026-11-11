#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define ull unsigned long long
#define endl '\n'
#define INF 0x3f3f3f3f
#define pll pair<int,int>
const int N=5e5+5;
ll n,a[N],m,p[N];
bool check(ll l,ll r){
	if(a[r]*(r-l+1)-(p[r]-p[l-1])<=m)return true;
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(1+a,1+a+n);
	for(int i=1;i<=n;i++)p[i]=p[i-1]+a[i];
	ll ans=0,l=0;
	for(int i=1;i<=n;i++){
		if(check(l,i))ans=max(ans,i-l+1);
		else{
			while(l<i&&!check(l,i))l++;
			ans=max(ans,i-l+1);
		}
	}
	cout<<ans;
	return 0;
}


