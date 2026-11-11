#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,ans;
ll a[N];
ll check(ll x){
	int cnt=0;
	ll s=m;
	for(int i=n;i>0;i--){
		if(a[i]<=x){
			s-=x-a[i];
			if(s<0)break;
			cnt++;
		}
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	ll d=a[2]-a[1];
	bool flag=true;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=d){
			flag=false;
			break;
		}
	}
	if(flag&&n>=2e4){
		int x=ceil((sqrt(8.0*m/d+1)-1)/2);
		cout<<x;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,check(a[i]));
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 5
1 2 4 8 9
5 5
1 3 5 7 9
*/
